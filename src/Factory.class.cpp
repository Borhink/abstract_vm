/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:28 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/14 14:17:44 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.class.hpp"

Factory::funcPtr1 const Factory::_create[5] = {&Factory::createInt8, &Factory::createInt16, &Factory::createInt32, &Factory::createFloat, &Factory::createDouble};


Factory::Factory(void)
{
}

Factory::Factory(Factory const &src)
{
	*this = src;
}

Factory::~Factory(void)
{
}

Factory &Factory::operator=(Factory const &rhs)
{
	if (this != &rhs)
	{
		//Copy
	}
	return (*this);
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	return ((this->*_create[type])(value));
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	return (new Operand<char>(value, Int8));
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	return (new Operand<short>(value, Int16));
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	return (new Operand<int>(value, Int32));
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	return (new Operand<float>(value, Float));
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	return (new Operand<double>(value, Double));
}
