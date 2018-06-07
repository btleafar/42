/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:30:59 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:31:00 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(void)
{
    return ;
}

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
{
    this->_damage = damage;
    this->_apcost = apcost;
    this->_name = name;
    return ;
}

AWeapon::AWeapon(const AWeapon &src)
{
    *this = src;
    return ;
}

AWeapon::~AWeapon(void)
{
    return ;
}

AWeapon
&AWeapon::operator= (const AWeapon &rhs)
{
    if (this != &rhs)
    {
        this->_damage = rhs._damage;
        this->_apcost = rhs._apcost;
        this->_name = rhs._name;
    }
    return (*this);
}

int
AWeapon::getAPCost(void) const
{
    return (this->_apcost);
}

int
AWeapon::getDamage(void) const
{
    return (this->_damage);
}

const std::string
AWeapon::getName() const
{
    return (this->_name);
}
