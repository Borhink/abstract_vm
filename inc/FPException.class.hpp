/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FPException.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:10:16 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/03 15:06:19 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPEXCEPTION_HPP
# define FPEXCEPTION_HPP

# include <stdexcept>

class FloatingPointException : public std::overflow_error
{

public:
	FloatingPointException(void);

	virtual char const *what() const throw();
};

#endif
