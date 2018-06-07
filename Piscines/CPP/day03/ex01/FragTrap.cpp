/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:28:46 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/07 20:28:47 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** Constructors and destructors
*/

FragTrap::FragTrap(void)
{
    return ;
}

FragTrap::~FragTrap(void)
{
    return ;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "I'm alive! They don't call me " \
              << name << " for nothing" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_meleeAttackDamagePoints = 30;
    this->_rangedAttackDamagePoints = 20;
    this->_armourDamageReductionPoints = 5;
    this->_vaulhunterDamagePoints = 0;
    this->_memeAttackDamagePoints = 9001;
    this->_fartAttackDamagePoints = 5;
    this->_weedAttackDamagePoints = 420;
    this->_troloAttackDamagePoints = 69;
    this->_laserAttackDamagePoints = 42;
    return ;
}

/*
** Operators
*/

FragTrap
&FragTrap::operator= (FragTrap const &rhs)
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
	this->_vaulhunterDamagePoints = rhs._vaulhunterDamagePoints;
	this->_memeAttackDamagePoints = rhs._memeAttackDamagePoints;
	this->_fartAttackDamagePoints = rhs._fartAttackDamagePoints;
	this->_weedAttackDamagePoints = rhs._weedAttackDamagePoints;
	this->_troloAttackDamagePoints = rhs._troloAttackDamagePoints;
	this->_laserAttackDamagePoints = rhs._laserAttackDamagePoints;
    return (*this);
}

/*
** Attacks
*/

void
FragTrap::meleeAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with melee, causing " << this->_meleeAttackDamagePoints \
              << " points of damage !" << std::endl;
}

void
FragTrap::rangedAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " at range, causing " << this->_rangedAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

/*
** Damage calculations
*/

void
FragTrap::takeDamage(unsigned int amount)
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
FragTrap::beRepaired(unsigned int amount)
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
** Random attacks
*/

void
FragTrap::vaulthunter_dot_exe(std::string const &target)
{
  int   random;

  if (this->_energyPoints < 25)
  {
        std::cout << this->_name << ": I need more energy... >.<" << std::endl;
        std::cout << "Energy points needed: " << 25 - this->_energyPoints \
                  << std::endl;
  }
  else
  {
        this->_energyPoints -= 25;
        srand(time(NULL));
        random = rand() % 5;
        if (random == 0)
            FragTrap::memeAttack(target);
        else if (random == 1)
            FragTrap::fartAttack(target);
        else if (random == 2)
            FragTrap::weedAttack(target);
        else if (random == 3)
            FragTrap::troloAttack(target);
        else
            FragTrap::laserAttack(target);
  }
  return ;
}

void
FragTrap::memeAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_memeAttackDamagePoints;
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with memes, causing over " << this->_memeAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void
FragTrap::fartAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_fartAttackDamagePoints;
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with a fart, causing " << this->_fartAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void
FragTrap::weedAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_weedAttackDamagePoints;
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with a joint, causing " << this->_weedAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void
FragTrap::troloAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_troloAttackDamagePoints;
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with skittles, causing " << this->_troloAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void
FragTrap::laserAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_laserAttackDamagePoints;
    std::cout << "FR4G-TP " << this->_name << " attacks " << target \
              << " with a laser, causing " << this->_laserAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

/*
** Get methods
*/

std::string
FragTrap::getName(void)
{
    return (this->_name);
}

unsigned int
FragTrap::getMeleeAttackDamage(void)
{
    return (this->_meleeAttackDamagePoints);
}

unsigned int
FragTrap::getRangedAttackDamage(void)
{
    return (this->_rangedAttackDamagePoints);
}

unsigned int
FragTrap::getArmourDamageReduction(void)
{
    return (this->_armourDamageReductionPoints);
}

unsigned int
FragTrap::getVaulHunter_dot_exeDamage(void)
{
    return (this->_vaulhunterDamagePoints);
}

unsigned int
FragTrap::getMemeAttackDamage(void)
{
    return (this->_memeAttackDamagePoints);
}

unsigned int
FragTrap::getFartAttackDamage(void)
{
    return (this->_fartAttackDamagePoints);
}

unsigned int
FragTrap::getWeedAttackDamage(void)
{
    return (this->_weedAttackDamagePoints);
}

unsigned int
FragTrap::getTroloAttackDamage(void)
{
    return (this->_troloAttackDamagePoints);
}

unsigned int
FragTrap::getLaserAttackDamage(void)
{
    return (this->_laserAttackDamagePoints);
}
