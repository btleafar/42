/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:41:07 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:41:08 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
    return ;
}

TacticalMarine::TacticalMarine(const TacticalMarine &src)
{
    *this = src;
    std::cout << "Tactical Marine ready for battle" << std::endl;
    return ;
}


TacticalMarine::~TacticalMarine(void)
{
    std::cout << "Aaargh ..." << std::endl;
    return ;
}


TacticalMarine
&TacticalMarine::operator= (const TacticalMarine &rhs)
{
	(void)rhs;
	return (*this);
}


void
TacticalMarine::battleCry(void) const
{
    std::cout << "For the holy PLOT !" << std::endl;
    return ;
}

void
TacticalMarine::meleeAttack(void) const
{
    std::cout << "* attacks with chainsword *" << std::endl;
    return ;
}

void
TacticalMarine::rangedAttack(void) const
{
    std::cout << "* attacks with bolter *" << std::endl;
    return ;
}

ISpaceMarine
*TacticalMarine::clone(void) const
{
    return (new TacticalMarine);
}
