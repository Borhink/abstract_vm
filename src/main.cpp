/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:56:50 by qhonore           #+#    #+#             */
/*   Updated: 2018/02/14 14:19:55 by qhonore          ###   ########.fr       */
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
					std::cout << std::endl << "==================================" << std::endl;
				vm.run(av[i]);
				first = false;
			}
		}
	}
	else
		vm.run(nullptr);
	return (0);
}
