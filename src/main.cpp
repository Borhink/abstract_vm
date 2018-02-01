/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:56:50 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/01 21:13:51 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AbstractVM.class.hpp"

# include <sstream>
# include <iostream>
int main(void)
{
	// AbstractVM vm;
    //
	// vm.run();
	try
	{
		int a = 0;
		std::stringstream ss(std::string("-2147483649"));

		ss >> a;
		if (ss.fail())
		{
			if (a == std::numeric_limits<int>::max())
				throw std::overflow_error("int overflow");
			else if (a == std::numeric_limits<int>::min())
				throw std::overflow_error("int underflow");
		}
		else
			std::cout << a << std::endl;

		// std::cout << stoi(std::string("999999999999")) << std::endl;
		}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		double b;
		std::stringstream ss(std::string("179769999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0"));

		ss >> b;
		if (ss.fail() || b > std::numeric_limits<double>::max())
			throw std::overflow_error("double overflow");
		else if (ss.fail() || b < std::numeric_limits<double>::min())
			throw std::overflow_error("double underflow");
		else
			std::cout << b << std::endl;

		// std::cout << stod(std::string("179768999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0")) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

/*
• The assembly program includes one or several lexical errors or syntactic errors.
• An instruction is unknown
• Overflow on a value or the result of an operation TODO
• Underflow on a value or the result of an operation TODO
• Instruction pop on an empty stack
• Division/modulo by 0 TODO
• The program doesn’t have an exit instruction
• An assert instruction is not true
• The stack is composed of strictly less that two values when an arithmetic instruction
is executed.
*/
