/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:53:12 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:53:13 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string s, Weapon& w): _name(s), _weapon(w)
{
    return ;
}
HumanA::~HumanA(void)
{
    return ;
}

void
HumanA::attack(void)
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType();
    std::cout << std::endl;
    return ;
}
