/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:56:50 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/09 22:10:00 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.class.hpp"
#include "avm.hpp"

# include <sstream>
# include <iostream>
int main(int ac, char **av)
{
	AbstractVM vm;

	if (ac >= 2)
	{
		for (int i = 1; i < ac; i++)
		{
			if (std::string(av[i]) == "-t")
				test_all();
			else
				vm.run(av[i]);
		}
	}
	else
		vm.run(nullptr);
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
• If modulo between a float or double -> Error "invalid operands to binary expression" TODO

MY TESTS
this->createOperand(Int8, "127.00000001"); -> est OK, mais ne devrait pas
*/
