/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:46:43 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:46:44 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    return ;
}

Character::Character(const std::string &name)
{
    this->_name = name;
    this->_n_index = 0;
    for (int i = 0; i < 4; i += 1)
    {
        this->_inventory[i] = NULL;
    }
    return ;
}

Character::Character(const Character &src)
{
    *this = src;
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
        this->_name = rhs._name;
        this->_n_index = rhs._n_index;
        for (int i = 0; i < 4; i += 1)
        {
            this->_inventory[i] = NULL;
            this->_inventory[i] = rhs._inventory[i]->clone();
        }
    }
    return (*this);
}

const std::string
&Character::getName(void) const
{
    return (this->_name);
}

void
Character::equip(AMateria *m)
{
    if (this->_n_index < 3)
    {
        this->_inventory[this->_n_index] = m;
        this->_n_index += 1;
    }
    return ;
}

void
Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
    {
        this->_inventory[idx] = NULL;
    }
    return ;
}

void
Character::use(int idx, ICharacter &target)
{
    if (idx < this->_n_index)
    {
        this->_inventory[idx]->use(target);
    }
}
