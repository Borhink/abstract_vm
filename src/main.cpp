/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:56:50 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/13 17:43:26 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.class.hpp"
#include "avm.hpp"

# include <sstream>
# include <iostream>
int main(int ac, char **av)
{
	AbstractVM vm;
	bool first = true;

	if (ac >= 2)
	{
		for (int i = 1; i < ac; i++)
		{
			if (std::string(av[i]) == "-t")
				test_all();
			else
			{
				if (!first)
					std::cout << "==================================" << std::endl;
				vm.run(av[i]);
				first = false;
			}
		}
	}
	else
		vm.run(nullptr);
	return (0);
}

/*
• An instruction is unknown 	 														OK
• Overflow on a value or the result of an operation 	 								OK
• Underflow on a value or the result of an operation 	 								OK
• Division/modulo by 0 																	OK
• The assembly program includes one or several lexical errors or syntactic errors.		OK
• Instruction pop on an empty stack														OK
• An assert instruction is not true														OK
• The stack is composed of strictly less that two values when an arithmetic instruction
is executed.																			OK
• If modulo between a float or double -> Error "invalid operands to binary expression"	OK
• The program doesn’t have an exit instruction											OK

MY TESTS
this->createOperand(Int8, "127.00000001");	OK
*/
