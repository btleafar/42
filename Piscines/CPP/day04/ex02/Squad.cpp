/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:34:15 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:34:16 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(void)
{
    this->_nbr_units = 0;
    this->_squad = NULL;
    return ;
}

Squad::Squad(const Squad &src)
{
    this->_copyUnits(src);
    this->_nbr_units = src._nbr_units;
    return ;
}

Squad::~Squad(void)
{
    this->_destroyUnits();
    return ;
}

Squad
&Squad::operator= (const Squad &rhs)
{
    if (this != &rhs)
    {
        this->_destroyUnits();
        this->_copyUnits(rhs);
        this->_nbr_units = rhs._nbr_units;
    }
    return (*this);
}

int
Squad::push(ISpaceMarine *marine)
{
    t_container  *tmp;

    tmp = this->_squad;
    if (marine != NULL && this->_unitAlreadyIn(marine, tmp) == false)
    {
        tmp = this->_squad;
        if (this->_squad != NULL)
        {
            while (tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = new t_container;
            tmp->next->unit = marine;
            tmp->next->next = NULL;
        }
        else
        {
            this->_squad = new t_container;
            this->_squad->unit = marine;
            this->_squad->next = NULL;
        }
        this->_nbr_units += 1;
    }
    return (this->_nbr_units);
}


int
Squad::getCount(void) const
{
    return (this->_nbr_units);
}

ISpaceMarine
*Squad::getUnit(int n) const
{
    t_container  *tmp;

    tmp = this->_squad;
    if (n < 0 || n >= this->_nbr_units)
    {
        return (NULL);
    }
    while (n--)
    {
        tmp = tmp->next;
    }
    return (tmp->unit);
}

void
Squad::_copyUnits(const Squad &src)
{
    for (int i = 0; i < src.getCount(); i += 1)
    {
        push(src.getUnit(i));
    }
    return ;
}

void
Squad::_destroyUnits(void)
{
    t_container  *tmp;

    if (this->_squad != NULL)
    {
        delete this->_squad->unit;
        tmp = this->_squad;
        this->_squad = this->_squad->next;
        delete tmp;
        return (this->_destroyUnits());
    }
    return ;
}

bool
Squad::_unitAlreadyIn(ISpaceMarine *marine, t_container *squad)
{
    if (squad == NULL)
    {
        return (false);
    }
    else if (marine == squad->unit)
    {
        return (true);
    }
    else
    {
        return (this->_unitAlreadyIn(marine, squad->next));
    }
}
