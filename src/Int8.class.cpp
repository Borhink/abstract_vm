/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:45:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/01 22:05:43 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.class.hpp"

Int8::Int8(void):
_nb(0), _type(eOperandType::Int8)
{

}

Int8(char value):
_nb(value), _type(eOperandType::Int8)
{

}

Int8(std::string const &value):
_nb(0), _type(eOperandType::Int8)
{
	std::stringstream ss(value);

	ss >> _nb;
	if (ss.fail())
	{
		if (a == std::numeric_limits<char>::max())
			throw std::overflow_error("Int8 overflow");
		else if (a == std::numeric_limits<char>::min())
			throw std::underflow_error("Int8 underflow");
	}
}

Int8::Int8(Int8 const &src)
{
	*this = src;
}

Int8::~Int8(void)
{

}

Int8 &operator=(Int8 const &rhs)
{
	if (this != &rhs)
	{
		_nb = rhs._nb;
		_type = rhs._type;
	}
}

int Int8::getPrecision(void) const
{
	return (static_cast<int>(_type));
}

eOperandType Int8::getType(void) const
{
	return (_type);
}

Int8 Int8::operator+(Int8 const &rhs) const
{
	if (rhs._nb > 0 && _nb > std::numeric_limits<char>::max() - rhs._nb)
		throw std::overflow_error("Int8 overflow");
	if (rhs._nb < 0 && _nb < std::numeric_limits<char>::min() - rhs._nb)
		throw std::underflow_error("Int8 underflow");
	return (Int8(_nb + rhs._nb));
}

Int8 Int8::operator-(Int8 const &rhs) const
{
	if (rhs._nb < 0 && _nb > std::numeric_limits<char>::max() + rhs._nb)
		throw std::overflow_error("Int8 overflow");
	if (rhs._nb > 0 && _nb < std::numeric_limits<char>::min() + rhs._nb)
		throw std::underflow_error("Int8 underflow");
	return (Int8(_nb - rhs._nb));
}

Int8 Int8::operator*(Int8 const &rhs) const
{
	if (_nb > std::numeric_limits<char>::max() / rhs._nb) /* `_nb * rhs._nb` would overflow */
		throw std::overflow_error("Int8 overflow");
	if ((_nb < std::numeric_limits<char>::min() / rhs._nb)) /* `_nb * rhs._nb` would underflow */
		throw std::underflow_error("Int8 underflow");
	// there may be need to check for -1 for two's complement machines
	if ((_nb == -1) && (rhs._nb == std::numeric_limits<char>::min())) /* `_nb * rhs._nb` can overflow */
		throw std::overflow_error("Int8 overflow");
	if ((rhs._nb == -1) && (_nb == std::numeric_limits<char>::min())) /* `_nb * rhs._nb` (or `_nb / rhs._nb`) can overflow */
		throw std::overflow_error("Int8 overflow");

	// • Overflow on a value or the result of an operation TODO
	// • Underflow on a value or the result of an operation TODO
	return (Int8(_nb * rhs._nb));
}

Int8 Int8::operator/(Int8 const &rhs) const
{
	// • Overflow on a value or the result of an operation TODO
	// • Underflow on a value or the result of an operation TODO
	// • Division/modulo by 0 TODO
	return (Int8(_nb / rhs._nb));
}

Int8 Int8::operator%(Int8 const &rhs) const
{
	// • Overflow on a value or the result of an operation TODO
	// • Underflow on a value or the result of an operation TODO
	// • Division/modulo by 0 TODO
	return (Int8(_nb % rhs._nb));
}

std::string const &Int8::toString(void) const
{
	std::stringstream sstream;

	sstream << _nb;
	return (sstream.str());
}
