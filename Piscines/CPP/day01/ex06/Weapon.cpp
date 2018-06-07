/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:52:58 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:53:00 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t): _type(t)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

void
Weapon::setType(std::string str)
{
    this->_type = str;
    return ;
}

const std::string&
Weapon::getType(void)
{
    return (this->_type);
}
