/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:40:03 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 03:40:04 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
    return ;
}

ZombieEvent::~ZombieEvent(void)
{
    return ;
}

void
ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
    return ;
}

std::string
ZombieEvent::getZombieType(void)
{
    return (this->_type);
}

Zombie
*ZombieEvent::newZombie(std::string name)
{
    return (new Zombie(_type, name));
}

Zombie
*ZombieEvent::randomChump(void)
{
    int     index;
    int     names_nbr;
    Zombie  *zombie;
    std::string names[] = {"Angel", "Eugenio", "Gerardo", "Giacomo", "Ignacio"};

    if (this->_type == "")
        this->setZombieType("ded");
    names_nbr = 5;
    index = rand() % names_nbr;
    zombie = this->newZombie(names[index]);
    return (zombie);
}
