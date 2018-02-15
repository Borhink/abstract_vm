/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:56:50 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/15 17:18:41 by qhonore          ###   ########.fr       */
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
					std::cout << "===================== File "\
						<< av[i] << " =====================" << std::endl;
					vm.run(av[i], verbose);
					if (i + 1 != ac)
						std::cout << std::endl;
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

couleurs											OK
Multi fichiers										OK
-t Pleins de test									OK
Notation scientifique								OK
-v verbose											OK
instruction rev (reverse last two param)			OK
instruction min										OK
instruction max										OK
instruction avg (average)							OK
instruction and &									OK
instruction or |									OK
instruction xor ^									OK
*/
