/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:28 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/30 16:53:09 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.class.hpp"

AbstractVM::funcPtr const AbstractVM::_create[5] = {&AbstractVM::createInt8, &AbstractVM::createInt16, &AbstractVM::createInt32, &AbstractVM::createFloat, &AbstractVM::createDouble};

AbstractVM::AbstractVM(void):
_run(true)
{

}

AbstractVM::AbstractVM(AbstractVM const &src)
{
	*this = src;
}

AbstractVM::~AbstractVM(void)
{

}

AbstractVM &operator=(AbstractVM const &rhs)
{
	if (this != &rhs)
	{
		_run = rhs._run;
	}
}

void AbstractVM::run(void)
{
	std::string buff;

	while (_run)
	{
		std::getline(std::cin, buff);
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

IOperand const *createInt8(std::string const &value) const
{
	_operands.push(new Int8(value));
	return (_operands.top());
}

IOperand const *createInt16(std::string const &value) const
{
	_operands.push(new Int16(value));
	return (_operands.top());
}

IOperand const *createInt32(std::string const &value) const
{
	_operands.push(new Int32(value));
	return (_operands.top());
}

IOperand const *createFloat(std::string const &value) const
{
	_operands.push(new Float(value));
	return (_operands.top());
}

IOperand const *createDouble(std::string const &value) const
{
	_operands.push(new Double(value));
	return (_operands.top());
}
