/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:45:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/30 17:30:44 by qhonore          ###   ########.fr       */
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
_type(eOperandType::Int8)
{
	if (std::numeric_limits<char>::min())
	// • Overflow on a value or the result of an operation TODO
	// • Underflow on a value or the result of an operation TODO
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
	// • Overflow on a value or the result of an operation TODO
	// • Underflow on a value or the result of an operation TODO
	return (Int8(_nb + rhs._nb));
}

Int8 Int8::operator-(Int8 const &rhs) const
{
	// • Overflow on a value or the result of an operation TODO
	// • Underflow on a value or the result of an operation TODO
	return (Int8(_nb - rhs._nb));
}

Int8 Int8::operator*(Int8 const &rhs) const
{
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
