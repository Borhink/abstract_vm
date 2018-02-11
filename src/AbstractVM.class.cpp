/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:28 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/11 19:32:48 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.class.hpp"

AbstractVM::funcPtr1 const AbstractVM::_create[5] = {&AbstractVM::createInt8, &AbstractVM::createInt16, &AbstractVM::createInt32, &AbstractVM::createFloat, &AbstractVM::createDouble};
std::map<std::string, AbstractVM::funcPtr2> const AbstractVM::_inst = AbstractVM::initInst();
std::map<std::string, AbstractVM::funcPtr2> const AbstractVM::_types = AbstractVM::initTypes();

AbstractVM::AbstractVM(void):
_run(true), _exit(false), _operands(new Stack<IOperand*>)
{

}

AbstractVM::AbstractVM(AbstractVM const &src)
{
	*this = src;
}

AbstractVM::~AbstractVM(void)
{
	while (!_operands->empty())
	{
		delete _operands->top();
		_operands->pop();
	}
	delete _operands;
}

std::map<std::string, AbstractVM::funcPtr2> AbstractVM::initInst(void)
{
	std::map<std::string, AbstractVM::funcPtr2> map;

	map["push"] = &AbstractVM::parsePush;
	map["pop"] = &AbstractVM::parsePop;
	map["dump"] = &AbstractVM::parseDump;
	map["assert"] = &AbstractVM::parseAssert;
	map["add"] = &AbstractVM::parseAdd;
	map["sub"] = &AbstractVM::parseSub;
	map["mul"] = &AbstractVM::parseMul;
	map["div"] = &AbstractVM::parseDiv;
	map["mod"] = &AbstractVM::parseMod;
	map["print"] = &AbstractVM::parsePrint;
	map["exit"] = &AbstractVM::parseExit;
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
	}
	return (*this);
}

void AbstractVM::run(char *path)
{
	std::string buff;
	std::fstream file;
	int line = 0;

	if (path)
	{
		file.open(path);
		if (!file.is_open())
		{
			std::cout << "Opening \"" << path << "\" failed" << std::endl;
			return;
		}
		_isFile = true;
	}
	else
		_isFile = false;
	while (_run)
	{
		std::getline((_isFile ? file : std::cin), buff);
		try
		{
			if (!buff.empty())
				this->parseInstruction(buff);
		}
		catch (std::exception &e)
		{
			std::cout << "Line " << line << " \"" << YELLOW << buff << EOC << "\": " << RED << e.what() << EOC << std::endl;
		}
		line++;
	}
	if (_isFile)
		file.close();
}

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
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		pos = line.find(";");
		if (pos == 0)
			return;
		line = line.substr(0, pos);
		this->purifyString(line);
		instruction = line.substr(0, line.find(" "));
		if (AbstractVM::_inst.find(instruction) != _inst.end())
			(this->*_inst.at(instruction))(line);
		else
			throw UnknowInstructionException();
	}
}

void AbstractVM::parsePush(std::string const &line)
{
	this->parseArg(line);

	(void)line;
}

void AbstractVM::parsePop(std::string const &line)
{
	std::cout << "parsePop" << std::endl;
	(void)line;
}

void AbstractVM::parseDump(std::string const &line)
{
	std::cout << "parseDump" << std::endl;
	(void)line;
}

void AbstractVM::parseAssert(std::string const &line)
{
	std::cout << "parseAssert" << std::endl;
	(void)line;
}

void AbstractVM::parseAdd(std::string const &line)
{
	std::cout << "parseAdd" << std::endl;
	(void)line;
}

void AbstractVM::parseSub(std::string const &line)
{
	std::cout << "parseSub" << std::endl;
	(void)line;
}

void AbstractVM::parseMul(std::string const &line)
{
	std::cout << "parseMul" << std::endl;
	(void)line;
}

void AbstractVM::parseDiv(std::string const &line)
{
	std::cout << "parseDiv" << std::endl;
	(void)line;
}

void AbstractVM::parseMod(std::string const &line)
{
	std::cout << "parseMod" << std::endl;
	(void)line;
}

void AbstractVM::parsePrint(std::string const &line)
{
	std::cout << "parsePrint" << std::endl;
	(void)line;
}

void AbstractVM::parseExit(std::string const &line)
{
	std::cout << "parseExit" << std::endl;
	(void)line;
}

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
	for (size_t i = 0; i < value.size(); i++)
		if (!isdigit(value[i]))
			throw LexicalSyntacticException("Syntactic exception (Value is not an integer)");
}

void AbstractVM::checkDecimal(std::string const &value)
{
	bool dot = false;
	double test = 2.;
	double test2 = .2;
	test = test2;

	if (value == ".")
		throw LexicalSyntacticException("Syntactic exception (Value is not a decimal number)");
	for (size_t i = 0; i < value.size(); i++)
		if (!isdigit(value[i]))
		{
			if (value[i] != '.' || dot)
				throw LexicalSyntacticException("Syntactic exception (Value is not a decimal number)");
			dot = true;
		}
}

void AbstractVM::parseInt8(std::string const &value)
{
	this->checkInteger(value);
	this->createOperand(Int8, value);
}

void AbstractVM::parseInt16(std::string const &value)
{
	this->checkInteger(value);
	this->createOperand(Int16, value);
}

void AbstractVM::parseInt32(std::string const &value)
{
	this->checkInteger(value);
	this->createOperand(Int32, value);
}

void AbstractVM::parseFloat(std::string const &value)
{
	this->checkDecimal(value);
	this->createOperand(Float, value);
}

void AbstractVM::parseDouble(std::string const &value)
{
	this->checkDecimal(value);
	this->createOperand(Double, value);
}

IOperand const *AbstractVM::createOperand(eOperandType type, std::string const &value) const
{
	return ((this->*_create[type])(value));
}

IOperand const *AbstractVM::createInt8(std::string const &value) const
{
	_operands->push(new Operand<char>(value, Int8));
	return (_operands->top());
}

IOperand const *AbstractVM::createInt16(std::string const &value) const
{
	_operands->push(new Operand<short>(value, Int16));
	return (_operands->top());
}

IOperand const *AbstractVM::createInt32(std::string const &value) const
{
	_operands->push(new Operand<int>(value, Int32));
	return (_operands->top());
}

IOperand const *AbstractVM::createFloat(std::string const &value) const
{
	_operands->push(new Operand<float>(value, Float));
	return (_operands->top());
}

IOperand const *AbstractVM::createDouble(std::string const &value) const
{
	_operands->push(new Operand<double>(value, Double));
	return (_operands->top());
}
