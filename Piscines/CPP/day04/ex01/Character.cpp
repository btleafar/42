/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:31:09 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:31:10 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    return ;
}

Character::Character(const Character &src)
{
    *this = src;
    return ;
}

Character::Character(const std::string &name)
{
    this->_ap = 40;
    this->_name = name;
    this->_weapon = NULL;
    return ;
}

Character::~Character(void)
{
    return ;
}

Character
&Character::operator= (const Character &rhs)
{
    if (this != &rhs)
    {
        this->_ap = rhs._ap;
        this->_name = rhs._name;
        this->_weapon = rhs._weapon;
    }
    return (*this);
}

std::ostream
&operator<< (std::ostream &out, const Character &rhs)
{
    if (rhs.getWeapon() != NULL)
    {
        out << rhs.getName() << " has " << rhs.getAP() \
            << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    }
    else
    {
        out << rhs.getName() << " has " << rhs.getAP() \
            << " AP and is unarmend" << std::endl;
    }
    return (out);
}

void
Character::recoverAP(void)
{
    if (this->_ap <= 30)
    {
        this->_ap += 10;
    }
    else
    {
        this->_ap = 40;
    }
    return ;
}

void
Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
    return ;
}

void
Character::attack(Enemy *enemy)
{
    int   ap_cost;

    if (this->_weapon != NULL && enemy != NULL)
    {
        ap_cost = this->_weapon->getAPCost();
        if (this->_ap - ap_cost >= 0)
        {
          this->_weapon->attack();
          enemy->takeDamage(this->_weapon->getDamage());
          if (enemy->getHP() <= 0)
              delete enemy;
          this->_ap -= ap_cost;
          std::cout << this->_name << " attacks " << enemy->getType() \
                    << "with a " << this->_weapon->getName() << std::endl;
        }
    }
    return ;
}

int
Character::getAP(void) const
{
    return (this->_ap);
}

AWeapon
*Character::getWeapon(void) const
{
    return (this->_weapon);
}

const std::string
Character::getName(void) const
{
    return (this->_name);
}
