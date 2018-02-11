/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:10:16 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/11 16:59:42 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <stdexcept>
# include <string>

class FloatingPointException : public std::overflow_error
{

public:
	FloatingPointException(void);

	virtual char const *what() const throw();
};

class UnknowInstructionException : public std::runtime_error
{

public:
	UnknowInstructionException(void);

	virtual char const *what() const throw();
};

class LexicalSyntacticException : public std::runtime_error
{

public:
	LexicalSyntacticException(void);
	LexicalSyntacticException(char const *what);

	virtual char const *what() const throw();
};

#endif
