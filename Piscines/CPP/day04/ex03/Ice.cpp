/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:47:08 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:47:08 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    return ;
}

Ice::Ice(const Ice &src)
{
    *this = src;
    return ;
}

Ice::~Ice(void)
{
    return ;
}

Ice
&Ice::operator= (const Ice &rhs)
{
    if (this != &rhs)
    {
        this->xp_ = rhs.xp_;
    }
    return (*this);
}

AMateria
*Ice::clone(void) const
{
    return (new Ice());
}

void
Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" \
              << std::endl;
    return ;
}
