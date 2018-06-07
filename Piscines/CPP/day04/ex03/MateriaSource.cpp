/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:47:44 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:47:45 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    this->_n_index = 0;
    for (int i = 0; i < 4; i += 1)
    {
        this->_inventory[i] = NULL;
    }
    return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    *this = src;
    return ;
}

MateriaSource::~MateriaSource(void)
{
    return ;
}

MateriaSource
&MateriaSource::operator= (const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i += 1)
        {
            this->_inventory[i] = NULL;
            this->_inventory[i] = rhs._inventory[0]->clone();
        }
        this->_n_index = rhs._n_index;
    }
    return (*this);
}

void
MateriaSource::learnMateria(AMateria *m)
{
    if (this->_n_index < 3)
    {
        this->_inventory[this->_n_index] = m;
        this->_n_index += 1;
    }
}

AMateria
*MateriaSource::createMateria(const std::string &type)
{
    if (type == "ice")
    {
        return (new Ice());
    }
    else if (type == "cure")
    {
        return (new Cure());
    }
    return (NULL);
}
