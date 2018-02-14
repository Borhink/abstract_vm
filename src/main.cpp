/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:56:50 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/14 19:09:39 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.class.hpp"
#include "avm.hpp"

# include <sstream>
# include <iostream>
int main(int ac, char **av)
{
	AbstractVM vm;
	bool file = false;
	bool first = true;
	bool test = false;
	bool verbose = false;

	if (ac >= 2)
	{
		for (int i = 1; i < ac; i++)
		{
			if (std::string(av[i]) == "-t")
				test = true;
			else if (std::string(av[i]) == "-v")
				verbose = true;
			else
				file = true;
		}
		if (test)
			test_all();
		if (file)
		{
			for (int i = 1; i < ac; i++)
			{
				if (std::string(av[i]) != "-t" && std::string(av[i]) != "-v")
				{
					if (!first)
						std::cout << std::endl << "==================================" << std::endl;
					vm.run(av[i], verbose);
					first = false;
				}
			}
		}
	}
	if (!file)
		vm.run(nullptr, verbose);
	return (0);
}
/*
BONUS

Multi fichiers				OK
-t Pleins de test			OK
Notation scientifique		OK
-v verbose					OK
instruction suppl2 : rev (reverse last two param) OK
instruction suppl4 : log TODO
instruction suppl : (min, max, avg, pow) TODO
instruction suppl3 :  (and or xor) TODO

*/
