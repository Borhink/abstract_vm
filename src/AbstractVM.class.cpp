/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:28 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/15 16:49:11 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.class.hpp"

std::map<std::string, AbstractVM::funcPtr2> const AbstractVM::_inst = AbstractVM::initInst();
std::map<std::string, AbstractVM::funcPtr2> const AbstractVM::_types = AbstractVM::initTypes();

AbstractVM::AbstractVM(void):
_operands(new Stack<IOperand const*>), _factory()
{

}

AbstractVM::AbstractVM(AbstractVM const &src)
{
	*this = src;
}

AbstractVM::~AbstractVM(void)
{
	this->clearStack();
	delete _operands;
}

void AbstractVM::clearStack(void)
{
	while (!_operands->empty())
	{
		delete _operands->top();
		_operands->pop();
	}
}

std::map<std::string, AbstractVM::funcPtr2> AbstractVM::initInst(void)
{
	std::map<std::string, AbstractVM::funcPtr2> map;

	map["push"] = &AbstractVM::Push;
	map["pop"] = &AbstractVM::Pop;
	map["dump"] = &AbstractVM::Dump;
	map["assert"] = &AbstractVM::Assert;
	map["add"] = &AbstractVM::Add;
	map["sub"] = &AbstractVM::Sub;
	map["mul"] = &AbstractVM::Mul;
	map["div"] = &AbstractVM::Div;
	map["mod"] = &AbstractVM::Mod;
	map["print"] = &AbstractVM::Print;
	map["exit"] = &AbstractVM::Exit;
	map["rev"] = &AbstractVM::Rev;
	map["and"] = &AbstractVM::And;
	map["or"] = &AbstractVM::Or;
	map["xor"] = &AbstractVM::Xor;
	map["min"] = &AbstractVM::Min;
	map["max"] = &AbstractVM::Max;
	map["avg"] = &AbstractVM::Avg;
	return (map);
}

std::map<std::string, AbstractVM::funcPtr2> AbstractVM::initTypes(void)
{
	std::map<std::string, AbstractVM::funcPtr2> map;

	map["int8"] = &AbstractVM::parseInt8;
	map["int16"] = &AbstractVM::parseInt16;
	map["int32"] = &AbstractVM::parseInt32;
	map["float"] = &AbstractVM::parseFloat;
	map["double"] = &AbstractVM::parseDouble;
	return (map);
}

AbstractVM &AbstractVM::operator=(AbstractVM const &rhs)
{
	if (this != &rhs)
	{
		_run = rhs._run;
		_exit = rhs._exit;
		_isFile = rhs._isFile;
		_verbose = rhs._verbose;
		_factory = rhs._factory;
		this->clearStack();
		for (Stack<IOperand const*>::iterator it = _operands->begin(); it != _operands->end(); ++it)
			_operands->push(_factory.createOperand((*it)->getType(), (*it)->toString()));
	}
	return (*this);
}

void AbstractVM::run(char *path, bool verbose)
{
	std::string buff;
	std::fstream file;
	int line = 1;

	if (path)
	{
		file.open(path);
		if (!file.is_open())
		{
			std::cout << RED << "Opening \"" << path << "\" failed" << EOC << std::endl;
			return;
		}
		_isFile = true;
	}
	else
		_isFile = false;
	_run = true;
	_exit = false;
	_verbose = verbose;
	std::cout << "Abstract VM " << GREEN << "starting" << EOC << "..." << std::endl;
	while (_run)
	{
		std::getline((_isFile ? file : std::cin), buff);
		if (_isFile && file.eof())
			_run = false;
		try
		{
			if (!buff.empty())
				this->parseInstruction(buff);
			if (!_run && !_exit)
				throw std::logic_error("No exit instruction exception");
		}
		catch (std::exception &e)
		{
			if (!buff.empty())
				std::cout << "Line " << line << " \"" << YELLOW << buff << EOC << "\": ";
			std::cout << RED << e.what() << EOC << std::endl;
		}
		line++;
	}
	std::cout << "Abstract VM " << RED << "shutdown" << EOC << "..." << std::endl;
	if (_isFile)
		file.close();
	this->clearStack();
}

/******************************************************************************\
|*************************** PARSE INSTRUCTION ********************************|
\******************************************************************************/

void AbstractVM::purifyString(std::string &str) const
{
	str = std::regex_replace(str, std::regex("[' '|'\t']{2,}"), " ");
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');

	if (first != std::string::npos)
		str = str.substr(first, (last - first + 1));
	if (str == std::string(" "))
		str = "";
}

void AbstractVM::parseInstruction(std::string line)
{
	std::string instruction;
	size_t pos;

	this->purifyString(line);
	if (!_isFile && line == ";;")
		_run = false;
	else
	{
		pos = line.find(";");
		if (pos == 0)
		{
			if (_verbose)
				std::cout << GREEN << line << EOC << std::endl;
			return;
		}
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		line = line.substr(0, pos);
		this->purifyString(line);
		if (!line.empty() && _exit)
			throw std::logic_error("VM already exit exception");
		instruction = line.substr(0, line.find(" "));
		if (AbstractVM::_inst.find(instruction) != _inst.end())
			(this->*_inst.at(instruction))(line);
		else
			throw UnknowInstructionException();
	}
}

void AbstractVM::checkLine(std::string const &line)
{
	if (line.find(" ") != std::string::npos)
		throw LexicalSyntacticException("Syntactic exception (Too much arguments)");
}

/******************************************************************************\
|********************************* PRINT **************************************|
\******************************************************************************/

std::string AbstractVM::printInstruction(std::string const &line, bool args)
{
	std::stringstream ss;

	if (args)
	{
		std::string arg = line.substr(line.find(" "));
		std::string value = arg.substr(arg.find("(") + 1, arg.find(")") - arg.find("(") - 1);

		ss << YELLOW << line.substr(0, line.find(" "))\
			<< MAGENTA << arg.substr(0, arg.find("("))\
			<< EOC << "(" << CYAN << value << EOC << ")";
	}
	else
	{
		if (line.find(" ") != std::string::npos)
			ss << YELLOW << line.substr(0, line.find(" ")) << EOC;
		else
			ss << YELLOW << line << EOC;
	}
	return (ss.str());
}

void AbstractVM::printOperation(std::string const &line, IOperand const *left,\
	IOperand const *right, IOperand const *result, std::string const &op)
{
	std::cout << this->printInstruction(line, false)\
		<< " " << MAGENTA << Operand<int>::toStringType(left) << EOC\
		<< "(" << CYAN << left->toString() << EOC << ")"\
		<< op << MAGENTA << Operand<int>::toStringType(right) << EOC\
		<< "(" << CYAN << right->toString() << EOC << ")"\
		<< " = " << MAGENTA << Operand<int>::toStringType(result) << EOC\
		<< "(" << CYAN << result->toString() << EOC << ")" << std::endl;
}

void AbstractVM::printFunction(std::string const &line, IOperand const *left,\
	IOperand const *right, IOperand const *result, std::string const &function)
{
	std::cout << this->printInstruction(line, false)\
		<< function << MAGENTA << Operand<int>::toStringType(left) << EOC\
		<< "(" << CYAN << left->toString() << EOC << ")"\
		<< ", " << MAGENTA << Operand<int>::toStringType(right) << EOC\
		<< "(" << CYAN << right->toString() << EOC << ")"\
		<< ") = " << MAGENTA << Operand<int>::toStringType(result) << EOC\
		<< "(" << CYAN << result->toString() << EOC << ")" << std::endl;
}

/******************************************************************************\
|***************************** INSTRUCTIONS ***********************************|
\******************************************************************************/

void AbstractVM::Push(std::string const &line)
{
	this->parseArg(line);
	if (_verbose)
		std::cout << this->printInstruction(line, true) << std::endl;
}

void AbstractVM::Pop(std::string const &line)
{
	this->checkLine(line);
	if (_operands->empty())
		throw PopEmptyException();
	if (_verbose)
	{
		std::cout << this->printInstruction(line, false)\
			<< " " << MAGENTA << Operand<int>::toStringType(_operands->top()) << EOC\
			<< "(" << CYAN << _operands->top()->toString() << EOC << ")" << std::endl;
	}
	delete _operands->top();
	_operands->pop();
}

void AbstractVM::Dump(std::string const &line)
{
	this->checkLine(line);
	if (_verbose)
		std::cout << this->printInstruction(line, false) << std::endl;
	for (Stack<IOperand const*>::reverse_iterator it = _operands->rbegin(); it != _operands->rend(); ++it)
		std::cout << (*it)->toString() << std::endl;
}

void AbstractVM::Assert(std::string const &line)
{
	bool good = true;
	this->parseArg(line);
	if (((*_operands->crbegin())->toString() != (*(_operands->crbegin() + 1))->toString())
		|| ((*_operands->crbegin())->getType() != (*(_operands->crbegin() + 1))->getType()))
		good = false;
	delete _operands->top();
	_operands->pop();
	if (_verbose)
	{
		std::cout << this->printInstruction(line, true)\
			<< " == " << MAGENTA << Operand<int>::toStringType(_operands->top()) << EOC\
			<< "(" << CYAN << _operands->top()->toString() << EOC << ")" << std::endl;
	}
	if (!good)
		throw std::runtime_error("Assert not true exception");
}

void AbstractVM::Add(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = *left + *right;
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printOperation(line, left, right, result, " + ");
	delete left;
	delete right;
}

void AbstractVM::Sub(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = *left - *right;
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printOperation(line, left, right, result, " - ");
	delete left;
	delete right;
}

void AbstractVM::Mul(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = *left * *right;
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printOperation(line, left, right, result, " * ");
	delete left;
	delete right;
}

void AbstractVM::Div(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = *left / *right;
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printOperation(line, left, right, result, " / ");
	delete left;
	delete right;
}

void AbstractVM::Mod(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	if ((*_operands->crbegin())->getType() >= Float
	|| (*(_operands->crbegin() + 1))->getType() >= Float)
		throw std::runtime_error("Invalid operands to binary expression exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = *left % *right;
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printOperation(line, left, right, result, " % ");
	delete left;
	delete right;
}

void AbstractVM::Print(std::string const &line)
{
	Stack<IOperand const*>::const_reverse_iterator it = _operands->crbegin();
	this->checkLine(line);
	if ((*it)->getType() != Int8)
		throw std::runtime_error("Assert not true exception");
	if (_verbose)
		std::cout << this->printInstruction(line, false) << " ";
	std::cout << static_cast<char>(std::stoi((*it)->toString()));
	if (_verbose)
		std::cout << std::endl;
}

void AbstractVM::Exit(std::string const &line)
{
	this->checkLine(line);
	_exit = true;
	if (_verbose)
		std::cout << this->printInstruction(line, false) << std::endl;
}

void AbstractVM::Rev(std::string const &line)
{
	std::string next, instruction;
	IOperand const *left, *right;

	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	right = _operands->top();
	_operands->pop();
	left = _operands->top();
	_operands->pop();
	_operands->push(right);
	_operands->push(left);
	if (_verbose)
	{
		std::cout << this->printInstruction(line, false)\
			<< " " << MAGENTA << Operand<int>::toStringType(left) << EOC\
			<< "(" << CYAN << left->toString() << EOC << ")"\
			<< " <-> " << MAGENTA << Operand<int>::toStringType(right) << EOC\
			<< "(" << CYAN << right->toString() << EOC << ")" << std::endl;
	}
	if (line.find(" ") != std::string::npos)
	{
		next = line.substr(line.find(" ") + 1);
		instruction = next.substr(0, next.find(" "));
		if (AbstractVM::_inst.find(instruction) != _inst.end())
			(this->*_inst.at(instruction))(next);
		else
			throw UnknowInstructionException();
	}
}

void AbstractVM::And(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	if ((*_operands->crbegin())->getType() >= Float
	|| (*(_operands->crbegin() + 1))->getType() >= Float)
		throw std::runtime_error("Invalid operands to binary expression exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = *left & *right;
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printOperation(line, left, right, result, " & ");
	delete left;
	delete right;
}

void AbstractVM::Or(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	if ((*_operands->crbegin())->getType() >= Float
	|| (*(_operands->crbegin() + 1))->getType() >= Float)
		throw std::runtime_error("Invalid operands to binary expression exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = *left | *right;
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printOperation(line, left, right, result, " | ");
	delete left;
	delete right;
}

void AbstractVM::Xor(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	if ((*_operands->crbegin())->getType() >= Float
	|| (*(_operands->crbegin() + 1))->getType() >= Float)
		throw std::runtime_error("Invalid operands to binary expression exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = *left ^ *right;
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printOperation(line, left, right, result, " ^ ");
	delete left;
	delete right;
}

void AbstractVM::Min(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = left->min(*right);
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printFunction(line, left, right, result, " min(");
	delete left;
	delete right;
}

void AbstractVM::Max(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = left->max(*right);
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printFunction(line, left, right, result, " max(");
	delete left;
	delete right;
}

void AbstractVM::Avg(std::string const &line)
{
	IOperand const *left, *right, *result;

	this->checkLine(line);
	if (_operands->size() < 2)
		throw std::logic_error("Missing operand(s) exception");
	right = *(_operands->crbegin());
	left = *(_operands->crbegin() + 1);
	result = left->avg(*right);
	_operands->pop();
	_operands->pop();
	_operands->push(result);
	if (_verbose)
		this->printFunction(line, left, right, result, " avg(");
	delete left;
	delete right;
}

/******************************************************************************\
|****************************** PARSE ARGS ************************************|
\******************************************************************************/

void AbstractVM::parseArg(std::string const &line)
{
	size_t find, start, end;
	std::string arg, type, value;

	find = line.find(" ");
	if (find == std::string::npos)
		throw LexicalSyntacticException("Syntactic exception (Missing arg)");
	arg = line.substr(find + 1);
	start = arg.find("(");
	end = arg.find(")");
	if (start == std::string::npos || end == std::string::npos || start > end)
		throw LexicalSyntacticException("Syntactic exception (Missing or misplaced bracket)");
	if (end + 1 < arg.size())
		throw LexicalSyntacticException("Syntactic exception (Too much arguments)");
	type = arg.substr(0, start);
	if (AbstractVM::_types.find(type) != _types.end())
	{
		value = arg.substr(start + 1, (end - start - 1));
		this->purifyString(value);
		if (value.empty())
			throw LexicalSyntacticException("Syntactic exception (Missing value)");
		(this->*_types.at(type))(value);
	}
	else
		throw LexicalSyntacticException("Lexical exception (Unknow arg type)");
}

void AbstractVM::checkInteger(std::string const &value)
{
	if (value == "+" || value == "-"
	|| !std::regex_match(value, std::regex("^[+\\-]?(?:0|[1-9]\\d*)?$")))
		throw LexicalSyntacticException("Syntactic exception (Value is not an integer)");
}

void AbstractVM::checkDecimal(std::string const &value)
{
	if (value == "+" || value == "-" || value == "+." || value == "-." || value == "."
	|| !std::regex_match(value, std::regex("^[+\\-]?(?:|0|[1-9]\\d*)(?:\\.\\d*)?(?:[eE][+\\-]?\\d+)?$")))
		throw LexicalSyntacticException("Syntactic exception (Value is not a decimal number)");
}

void AbstractVM::parseInt8(std::string const &value)
{
	this->checkInteger(value);
	_operands->push(_factory.createOperand(Int8, value));
}

void AbstractVM::parseInt16(std::string const &value)
{
	this->checkInteger(value);
	_operands->push(_factory.createOperand(Int16, value));
}

void AbstractVM::parseInt32(std::string const &value)
{
	this->checkInteger(value);
	_operands->push(_factory.createOperand(Int32, value));
}

void AbstractVM::parseFloat(std::string const &value)
{
	this->checkDecimal(value);
	_operands->push(_factory.createOperand(Float, value));
}

void AbstractVM::parseDouble(std::string const &value)
{
	this->checkDecimal(value);
	_operands->push(_factory.createOperand(Double, value));
}
