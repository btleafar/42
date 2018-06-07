/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:46:29 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:46:30 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
    return ;
}

AMateria::AMateria(const std::string &type)
{
    this->xp_ = 0;
    this->_type = type;
    return ;
}

AMateria::AMateria(const AMateria &src)
{
    *this = src;
    return ;
}

AMateria::~AMateria(void)
{
    return ;
}

AMateria
&AMateria::operator= (const AMateria &rhs)
{
    if (this != &rhs)
    {
        this->xp_ = rhs.xp_;
        this->_type = rhs._type;
    }
    return (*this);
}

const std::string
&AMateria::getType(void) const
{
    return (this->_type);
}

unsigned int  AMateria::getXP(void) const
{
    return (this->xp_);
}
