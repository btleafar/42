/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 22:58:47 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/07 22:58:49 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

/*
** Helper functions
*/

static void
attackMessage(std::string name, std::string const &target, int damage_points, \
                std::string msg)
{
    std::cout << "NIJ4-TP " << name << " beats " << target << msg \
              << damage_points << " points of damage !" << std::endl;
}

/*
** Constructors and destructors
*/

NinjaTrap::NinjaTrap(void)
{
	return ;
}

NinjaTrap::NinjaTrap(std::string name)
{
	std::cout << "I think " << name << " is a ninja! :O" << std::endl;
	this->_name = name;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDamagePoints = 60;
	this->_rangedAttackDamagePoints = 5;
	this->_armourDamageReductionPoints = 0;
	return ;
}

NinjaTrap::~NinjaTrap(void)
{
	return ;
}

/*
** Operators
*/

NinjaTrap
&NinjaTrap::operator= (NinjaTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_level = rhs._level;
	this->_meleeAttackDamagePoints = rhs._meleeAttackDamagePoints;
	this->_rangedAttackDamagePoints = rhs._rangedAttackDamagePoints;
	this->_armourDamageReductionPoints = rhs._armourDamageReductionPoints;
    return (*this);
}

/*
** Attacks
*/

void
NinjaTrap::meleeAttack(std::string const &target)
{
	attackMessage(this->_name, target, this->_meleeAttackDamagePoints,
        " with a ninja star, generating ");
    return ;
}

void
NinjaTrap::rangedAttack(std::string const &target)
{
	attackMessage(this->_name, target, this->_meleeAttackDamagePoints,
        " with a nunchuck, generating ");
    return ;
}

/*
** Shoebox functions
*/

void
NinjaTrap::ninjaShoebox(ScavTrap& scav)
{
  	std::cout << this->_name << ": I SCAVenge you, " \
			<< scav.getName() << "... I don't even lol" << std::endl;
}

void
NinjaTrap::ninjaShoebox(ClapTrap& clap)
{
	std::cout << this->_name << ": I CLAP to your ignorance, " \
				<< clap.getName() << "..." << std::endl;
}

void
NinjaTrap::ninjaShoebox(FragTrap& frag)
{
	std::cout << this->_name << ": You want a FRAGment of me, " \
				<< frag.getName() << "?" << std::endl;
}

void
NinjaTrap::ninjaShoebox(NinjaTrap& ninja)
{
	std::cout << this->_name << ": I NINJA... fuck this puns. Good luck, "\
	 			<< ninja.getName() << std::endl;
}
