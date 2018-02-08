/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:28 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/08 21:13:14 by qhonore          ###   ########.fr       */
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

void AbstractVM::run(void)
{
	std::string buff;

	// while (_run)
	// {
	// 	std::getline(std::cin, buff);
	// 	if (buff == "exit")
	// 	{
	// 		std::cout << "Absract VM shutdswn..." << std::endl;
	// 		_run = false;
	// 	}
	// }"1.79769e+1"
	// "-2147483649"
	// this->createOperand(Int32, "-2147483648");
	// this->createOperand(Int32, "1");
	// IOperand *op1 = _operands->at(0);
	// IOperand *op2 = _operands->at(1);
	// std::cout << op1->toString() << " * " << op2->toString() << " = ";
	// IOperand const *res = *op1 * *op2;
	// std::cout << res->toString() << std::endl;
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
