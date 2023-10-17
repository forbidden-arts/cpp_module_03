/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:42:47 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/17 10:51:07 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors & Destructor
ClapTrap::ClapTrap(): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor for " << _name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor for " << _name << " called" << std::endl;
}

// Overload
ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << "\033[31m attacks\033[0m " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << ". No energy points left." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << ". No hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else if (this->_hitPoints > 0)
		this->_hitPoints = 0;
	else
	{
		std::cout << "\033[33mClapTrap " << this->_name << " is dead.\033[0m Stop already." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " \033[31mwas attacked\033[0m and lost " << amount << " hit points. It has " << this->_hitPoints << " left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && this->_hitPoints + amount <= 10)
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself and gained " << amount << " hit points. It now has " << this->_hitPoints << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot repair itself. No energy points left." << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot repair itself. No hit points." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " is already repaired." << std::endl;
}
