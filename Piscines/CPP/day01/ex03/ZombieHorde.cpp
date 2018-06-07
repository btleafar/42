/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 05:38:17 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 05:38:18 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n): _number(n)
{
    this->_zombie = new Zombie[n];

    for (int i = 0; i < this->_number; i += 1)
    {
        this->_zombie[i].setType("Horde");
        this->_zombie[i].setName(this->randomChump());
    }
    return ;
}

ZombieHorde::ZombieHorde(void)
{
    return ;
}

ZombieHorde::~ZombieHorde(void)
{
    return ;
}

std::string
ZombieHorde::randomChump(void)
{
    int     index;
    int     names_nbr;
    std::string names[] = {"Angel", "Eugenio", "Gerardo", "Giacomo", "Ignacio"};

    names_nbr = 5;
    index = rand() % names_nbr;
    return (names[index]);
}

void
ZombieHorde::announce(void)
{
    for (int i = 0; i < this->_number; i += 1)
    {
        std::cout << this->_zombie[i].announce() << std::endl;
    }
    return ;
}
