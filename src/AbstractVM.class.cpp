/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:28 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/09 22:12:41 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.class.hpp"

AbstractVM::funcPtr const AbstractVM::_create[5] = {&AbstractVM::createInt8, &AbstractVM::createInt16, &AbstractVM::createInt32, &AbstractVM::createFloat, &AbstractVM::createDouble};

AbstractVM::AbstractVM(void):
_run(true), _operands(new Stack<IOperand*>)
{

}

AbstractVM::AbstractVM(AbstractVM const &src)
{
	*this = src;
}

AbstractVM::~AbstractVM(void)
{
	delete _operands;
}

AbstractVM &AbstractVM::operator=(AbstractVM const &rhs)
{
	if (this != &rhs)
	{
		_run = rhs._run;
	}
	return (*this);
}

void AbstractVM::run(char *path)
{
	std::string buff;
	std::fstream file;

	if (path)
	{
		file.open(path);
		if (!file.is_open())
		{
			std::cout << "Opening failed" << std::endl;
			return;
		}
	}
	while (_run)
	{
		std::getline((file.is_open() ? file : std::cin), buff);
		if (buff == "exit")
		{
			std::cout << "Absract VM shutdown..." << std::endl;
			_run = false;
		}
	}
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
