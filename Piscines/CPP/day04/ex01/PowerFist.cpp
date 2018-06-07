/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:32:02 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:32:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : PowerFist::AWeapon("Power Fist", 8, 50)
{
    return ;
}

PowerFist::PowerFist(const PowerFist &src)
{
    *this = src;
    return ;
}

PowerFist::~PowerFist(void)
{
    return ;
}

PowerFist
&PowerFist::operator= (const PowerFist &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_apcost = rhs._apcost;
        this->_damage = rhs._damage;
    }
    return (*this);
}

void
PowerFist::attack(void) const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
	return ;
}
