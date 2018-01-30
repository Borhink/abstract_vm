/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:58:23 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/30 16:46:18 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Stack.class.hpp"
# include "IOperand.class.hpp"

class AbstractVM
{

public:

	typedef IOperand const *(AbstractVM::*funcPtr)(std::string const &);

	AbstractVM(void);
	AbstractVM(AbstractVM const &src);
	~AbstractVM(void);

	AbstractVM &operator=(AbstractVM const &rhs);

	void run(void);
	IOperand const *createOperand(eOperandType type, std::string const &value) const;

	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;

private:

	bool					_run;
	Stack<IOperand*>		_operands;
	static funcPtr const	_create[5];
};

#endif
