/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:11:32 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/17 11:30:43 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		ClapTrap a;
		ClapTrap b("Dan");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Rasmus");
		b.beRepaired(3);
	}
	std::cout << "\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		ScavTrap c;
		ScavTrap d("Super-Dan");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		c.attack("Society!");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Wimpy-Rasmus");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("Wimpy-Rasmus");
	}
		std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		FragTrap e;
		FragTrap f("Bored with this");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		e.highFiveGuys();
		e.attack("the need to do this");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("the need to do this");
		f.highFiveGuys();
	}
	return 0;
}
