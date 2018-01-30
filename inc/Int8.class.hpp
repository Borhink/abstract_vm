/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:34 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/30 17:30:26 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

# include <string>
# include <sstream>
# include <limits>

class Int8
{

public:

	Int8(void);
	Int8(char value);
	Int8(std::string const &value);
	Int8(Int8 const &src);

	Int8 &operator=(Int8 const &rhs);

	virtual int getPrecision(void) const;
	virtual eOperandType getType(void) const;

	virtual Int8 const *operator+(Int8 const &rhs) const;
	virtual Int8 const *operator-(Int8 const &rhs) const;
	virtual Int8 const *operator*(Int8 const &rhs) const;
	virtual Int8 const *operator/(Int8 const &rhs) const;
	virtual Int8 const *operator%(Int8 const &rhs) const;

	virtual std::string const &toString(void) const;

	virtual ~Int8(void);

private:

	char			_nb;
	eOperandType	_type;
};

#endif
