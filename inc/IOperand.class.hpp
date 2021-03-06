/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:34 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/15 13:18:33 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <string>

enum eOperandType
{
	Int8 = 0,
	Int16,
	Int32,
	Float,
	Double
};

class IOperand
{

public:

	virtual int getPrecision(void) const = 0; // Precision of the type of the instance
	virtual eOperandType getType(void) const = 0; // Type of the instance

	virtual IOperand const *operator+(IOperand const &rhs) const = 0; // Sum
	virtual IOperand const *operator-(IOperand const &rhs) const = 0; // Difference
	virtual IOperand const *operator*(IOperand const &rhs) const = 0; // Product
	virtual IOperand const *operator/(IOperand const &rhs) const = 0; // Quotient
	virtual IOperand const *operator%(IOperand const &rhs) const = 0; // Modulo

	//BONUS
	virtual IOperand const *operator&(IOperand const &rhs) const = 0; // And
	virtual IOperand const *operator|(IOperand const &rhs) const = 0; // Or
	virtual IOperand const *operator^(IOperand const &rhs) const = 0; // Xor
	virtual IOperand const *min(IOperand const &rhs) const = 0; // Min
	virtual IOperand const *max(IOperand const &rhs) const = 0; // Max
	virtual IOperand const *avg(IOperand const &rhs) const = 0; // Average

	virtual std::string const &toString(void) const = 0; // String representation of the instance

	virtual ~IOperand(void) {}
};

#endif
