/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:23 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/14 14:17:58 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <string>
# include "IOperand.class.hpp"
# include "Operand.class.hpp"

class Factory
{

public:

	typedef IOperand const *(Factory::*funcPtr1)(std::string const &) const;

	Factory(void);
	Factory(Factory const &src);
	~Factory(void);

	Factory &operator=(Factory const &rhs);

	IOperand const *createOperand(eOperandType type, std::string const &value) const;

	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;

private:

	static funcPtr1 const _create[5];

};

#endif
