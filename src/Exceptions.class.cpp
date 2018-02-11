/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:05:02 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/11 16:56:39 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.class.hpp"

FloatingPointException::FloatingPointException(void) : std::overflow_error("Floating point exception")
{
}

char const *FloatingPointException::what() const throw()
{
	return (std::overflow_error::what());
}

UnknowInstructionException::UnknowInstructionException(void) : std::runtime_error("Unknow instruction exception")
{
}

char const *UnknowInstructionException::what() const throw()
{
	return (std::runtime_error::what());
}

LexicalSyntacticException::LexicalSyntacticException(void) : std::runtime_error("Lexical or syntactic exception")
{
}

LexicalSyntacticException::LexicalSyntacticException(char const *what) : std::runtime_error(what)
{
}

char const *LexicalSyntacticException::what() const throw()
{
	return (std::runtime_error::what());
}
