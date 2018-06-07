/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:53:28 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:53:29 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string s): _name(s)
{
    return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void
HumanB::setWeapon(Weapon& w)
{
    this->_weapon = &w;
    return ;
}

void
HumanB::attack(void)
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType();
    std::cout << std::endl;
    return ;
}
