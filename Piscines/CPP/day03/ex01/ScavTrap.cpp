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
** Damage calculations
*/

void
ScavTrap::takeDamage(unsigned int amount)
{
    unsigned int    damage;

    damage = amount - this->_armourDamageReductionPoints;
    if (damage > this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << this->_name << ": LOL I'm ded already... X_X" << std::endl;
    }
    else
    {
        this->_hitPoints -= damage;
        std::cout << this->_name << ": I'm still alive. :D" << std::endl;
        std::cout << "Armour reduction: " << this->_armourDamageReductionPoints\
                  << std::endl;
        std::cout << "Damage taken: " << damage << std::endl;
        std::cout << "HP left: " << this->_hitPoints << " / " \
                  << this->_maxHitPoints << std::endl;
    }
    return ;
}

void
ScavTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints < amount)
    {
        std::cout << this->_name << ": Not enough energy... :(" << std::endl;
    }
    else
    {
        this->_energyPoints -= amount;
        this->_hitPoints = amount + this->_hitPoints;
        std::cout << this->_name << ": I'm healing myself... ;)" << std::endl;
        std::cout << "HP points: " << this->_hitPoints << std::endl;
    }
    std::cout << "Energy points left: " << this->_energyPoints << std::endl;
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
ScavTrap::getName(void)
{
    return (this->_name);
}

unsigned int
ScavTrap::getMeleeAttackDamage(void)
{
    return (this->_meleeAttackDamagePoints);
}

unsigned int
ScavTrap::getRangedAttackDamage(void)
{
    return (this->_rangedAttackDamagePoints);
}

unsigned int
ScavTrap::getArmourDamageReduction(void)
{
    return (this->_armourDamageReductionPoints);
}

std::string
ScavTrap::getChallenge(void)
{
    return (this->_challenge);
}
