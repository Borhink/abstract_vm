/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:56:50 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/30 18:01:34 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.class.hpp"

int main(void)
{
	AbstractVM vm;

	vm.run();
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



// try
// {
// 	std::cout << stoi(std::string("999")) << std::endl;
// 	std::cout << atoi("999") << std::endl;
//
// 	std::cout << stoi(std::string("99999999")) << std::endl;
// 	std::cout << stod(std::string("179768999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0")) << std::endl;
// }
// catch (std::exception &e)
// {
// 	std::cout << e.what() << std::endl;
// }
