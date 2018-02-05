/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:34 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/05 19:32:42 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

# include <string>
# include <sstream>
# include <limits>
# include "IOperand.class.hpp"
# include "FPException.class.hpp"

typedef struct
{
	double	min;
	double	max;
} t_types;

static t_types const	g_type[5] =
{
	{std::numeric_limits<char>::min(), std::numeric_limits<char>::max()},
	{std::numeric_limits<short>::min(), std::numeric_limits<short>::max()},
	{std::numeric_limits<int>::min(), std::numeric_limits<int>::max()},
	{-std::numeric_limits<float>::max(), std::numeric_limits<float>::max()},
	{-std::numeric_limits<double>::max(), std::numeric_limits<double>::max()}
};

template <typename T>
class Operand : public IOperand
{

public:

/******************************************************************************\
|*********************** CONSTRUCTOR / DESTRUCTOR *****************************|
\******************************************************************************/
	Operand(void):
	_nb(0), _type(eOperandType::Int8), _str("0")
	{

	}

	Operand(T value, eOperandType type):
	_nb(value), _type(type)
	{
		std::stringstream ss;

		ss.precision(std::numeric_limits<double>::max_digits10);
		if (_type == Int8)
			ss << static_cast<int>(_nb);
		else
			ss << std::fixed << _nb;
		_str = ss.str();
	}

	Operand(std::string const &value, eOperandType type):
	_nb(0), _type(type)
	{
		std::stringstream ss(value);
		std::stringstream ss2;
		double tmp;

		ss >> tmp;
		if (tmp > g_type[_type].max)
			throw std::overflow_error("overflow");
		if (tmp < g_type[_type].min)
			throw std::underflow_error("underflow");
		_nb = tmp;
		ss2.precision(std::numeric_limits<double>::max_digits10);
		if (_type == Int8)
			ss2 << std::fixed << static_cast<int>(_nb);
		else
			ss2 << std::fixed << _nb;
		_str = ss2.str();
	}

	Operand(Operand const &src) { *this = src; }

	virtual ~Operand(void) {}

/******************************************************************************\
|************************* OPERATORS OVERLOADING ******************************|
\******************************************************************************/
	Operand &operator=(Operand const &rhs)
	{
		if (this != &rhs)
		{
			_nb = rhs._nb;
			_type = rhs._type;
		}
		return (*this);
	}

	virtual IOperand const *operator+(IOperand const &rhs) const
	{
		eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
		double opL = Operand::convert<double>(*this);
		double opR = Operand::convert<double>(rhs);

		if (opR > 0 && opL > g_type[type].max - opR)
			throw std::overflow_error("overflow");
		if (opR < 0 && opL < g_type[type].min - opR)
			throw std::underflow_error("underflow");
		return (this->createOperand(type, opL + opR));
	}

	virtual IOperand const *operator-(IOperand const &rhs) const
	{
		eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
		double opL = Operand::convert<double>(*this);
		double opR = Operand::convert<double>(rhs);

		if (opR < 0 && opL > g_type[type].max + opR)
			throw std::overflow_error("overflow");
		if (opR > 0 && opL < g_type[type].min + opR)
			throw std::underflow_error("underflow");
		return (this->createOperand(type, opL - opR));
	}

	virtual IOperand const *operator*(IOperand const &rhs) const
	{
		eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
		double opL = Operand::convert<double>(*this);
		double opR = Operand::convert<double>(rhs);

		if ((opL == -1 && opR == g_type[type].min)
		|| (opR == -1 && opL == g_type[type].min)
		|| (opL > 0 && opR > 0 && opL > g_type[type].max / opR)
		|| (opL < 0 && opR < 0 && -opL > g_type[type].max / -opR))
			throw std::overflow_error("overflow");
		if ((opL > 0 && opR < 0 && opL > g_type[type].max / -opR)
		|| (opL < 0 && opR > 0 && -opL > g_type[type].max / opR))
			throw std::underflow_error("underflow");
		return (this->createOperand(type, opL * opR));
	}

	virtual IOperand const *operator/(IOperand const &rhs) const
	{
		eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
		double opL = Operand::convert<double>(*this);
		double opR = Operand::convert<double>(rhs);

		if (opR == 0)
			throw FloatingPointException();
		if (opL == g_type[type].min && opR == -1)
			throw std::overflow_error("overflow");
		return (this->createOperand(type, opL / opR));
	}

	virtual IOperand const *operator%(IOperand const &rhs) const
	{
		eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
		int opL = Operand::convert<int>(*this);
		int opR = Operand::convert<int>(rhs);

		if (opL == 0)
			throw FloatingPointException();
		return (this->createOperand(type, opL % opR));
	}

/******************************************************************************\
|*********************** PUBLICS MEMBERS FUNCTIONS ****************************|
\******************************************************************************/

	virtual int getPrecision(void) const
	{
		return (static_cast<int>(_type));
	}

	virtual eOperandType getType(void) const
	{
		return (_type);
	}

	virtual std::string const &toString(void) const
	{
		return (_str);
	}

	template <typename U>
	static U convert(IOperand const &op)
	{
		std::stringstream ss(op.toString());
		U nb;

		ss >> nb;
		return (nb);
	}

/******************************************************************************\
|********************** PRIVATES MEMBERS FUNCTIONS ****************************|
\******************************************************************************/
private:

	IOperand const *createOperand(eOperandType type, double value) const
	{
		IOperand *ret = nullptr;

		switch (type)
		{
			case Int8:
				ret = new Operand<char>(value, type);
			break;
			case Int16:
				ret = new Operand<short>(value, type);
			break;
			case Int32:
				ret = new Operand<int>(value, type);
			break;
			case Float:
				ret = new Operand<float>(value, type);
			break;
			case Double:
				ret = new Operand<double>(value, type);
			break;
		}
		return (ret);
	}

/******************************************************************************\
|********************** PRIVATES MEMBERS ATTRIBUTES ***************************|
\******************************************************************************/
	T				_nb;
	eOperandType	_type;
	std::string		_str;
};

#endif
