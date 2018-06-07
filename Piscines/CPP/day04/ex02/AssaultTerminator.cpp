/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:33:23 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:33:24 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
    std::cout << "* teleports from space *" << std::endl;
    return ;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &src)
{
    *this = src;
    std::cout << "* teleports from space *" << std::endl;
    return ;
}

AssaultTerminator::~AssaultTerminator(void)
{
    std::cout << "I’ll be back ..." << std::endl;
    return ;
}

AssaultTerminator
&AssaultTerminator::operator= (const AssaultTerminator &rhs)
{
    (void)rhs;
    return (*this);
}

void
AssaultTerminator::battleCry(void) const
{
    std::cout << "This code is unclean. PURIFY IT !" << std::endl;
    return ;
}

void
AssaultTerminator::meleeAttack(void) const
{
    std::cout << "* attacks with chainfists *" << std::endl;
    return ;
}

void
AssaultTerminator::rangedAttack(void) const
{
    std::cout << "* does nothing *" << std::endl;
    return ;
}

ISpaceMarine
*AssaultTerminator::clone(void) const
{
    return (new AssaultTerminator);
}
