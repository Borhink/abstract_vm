/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FPException.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:05:02 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/03 15:52:14 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FPException.class.hpp"

FloatingPointException::FloatingPointException(void) : std::overflow_error("Floating point exception")
{
}

char const *FloatingPointException::what() const throw()
{
	return (std::overflow_error::what());
}
