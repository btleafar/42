/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:32:25 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:32:26 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : SuperMutant::Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return ;
}

SuperMutant::SuperMutant(const SuperMutant &src)
{
    *this = src;
    return ;
}

SuperMutant::~SuperMutant(void)
{
    std::cout << "Aaargh ..." << std::endl;
    return ;
}

SuperMutant
&SuperMutant::operator= (const SuperMutant &rhs)
{
    if (this != &rhs)
    {
        this->_hp = rhs._hp;
        this->_type = rhs._type;
    }
    return (*this);
}

void
SuperMutant::takeDamage(int damage)
{
    damage -= 3;

    if (this->_hp - damage <= 0 && damage > 0)
    {
        this->_hp = 0;
    }
    else
    {
        this->_hp -= damage;
    }
    return ;
}
