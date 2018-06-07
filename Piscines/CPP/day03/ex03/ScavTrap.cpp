/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:54:18 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/07 20:54:19 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*
** Helper functions
*/

static void
attackMessage(std::string name, std::string const &target, int damage_points, \
                std::string msg)
{
    std::cout << "SC4V-TP " << name << " strikes " << target << msg \
              << damage_points << " points of damage !" << std::endl;
}

/*
** Constructors and destructors
*/

ScavTrap::ScavTrap(void)
{
    return ;
}

ScavTrap::~ScavTrap(void)
{
    return ;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "Hi, my name is " << name << " and welcome to your doom. >:)" \
              << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_level = 1;
    this->_meleeAttackDamagePoints = 20;
    this->_rangedAttackDamagePoints = 15;
    this->_armourDamageReductionPoints = 3;
    return ;
}

/*
** Operators
*/

ScavTrap
&ScavTrap::operator= (ScavTrap const &rhs)
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
ScavTrap::meleeAttack(std::string const &target)
{
    attackMessage(this->_name, target, this->_meleeAttackDamagePoints,
        " with a sword, inducing ");
    return ;
}

void
ScavTrap::rangedAttack(std::string const &target)
{
    attackMessage(this->_name, target, this->_meleeAttackDamagePoints,
        " with a slingshot, generating ");
    return ;
}

/*
** Random challenges
*/

void
ScavTrap::challengeNewcomer(std::string const &target)
{
    int         random;
    std::string challenge[] =
    {
        "take a laxative",
        "prepare and eat ramen using something other than water",
        "rub peanut butter all over your face, for absolute no reason",
        "tie your shoes the way you're not used to tying them",
        "cook yourself a lovely dinner and somehow incorporate pickles in it"
    };

    srand(time(NULL));
    random = rand() % 5;
	this->_challenge = challenge[random];
    std::cout << this->_name << ": I challenge you to " << this->_challenge \
              << " right now! Good luck, " << target \
              <<  "... Muahahaha :D" << std::endl;
    return ;
}

/*
** Get methods
*/

std::string
ScavTrap::getChallenge(void)
{
    return (this->_challenge);
}
