/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 23:26:15 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/07 23:26:15 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
	return ;
}

SuperTrap::SuperTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDamagePoints = 60;
	this->_rangedAttackDamagePoints = 20;
	this->_armourDamageReductionPoints = 5;
	return ;
}

SuperTrap::~SuperTrap(void)
{
	return ;
}

SuperTrap
&SuperTrap::operator= (const SuperTrap &rhs)
{
    this->_hitPoints = rhs._hitPoints;
    this->_maxHitPoints = rhs._maxHitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_maxEnergyPoints = rhs._maxEnergyPoints;
    this->_level = rhs._level;
    this->_name = rhs._name;
    this->_meleeAttackDamagePoints = rhs._meleeAttackDamagePoints;
    this->_rangedAttackDamagePoints = rhs._rangedAttackDamagePoints;
    this->_armourDamageReductionPoints = rhs._armourDamageReductionPoints;
	return (*this);
}

void
SuperTrap::meleeAttack(std::string const &target)
{
	return (FragTrap::rangedAttack(target));
}

void
SuperTrap::rangedAttack(std::string const &target)
{
	return (NinjaTrap::meleeAttack(target));
}
