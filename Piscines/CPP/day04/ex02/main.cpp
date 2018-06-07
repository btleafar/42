/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:34:04 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:34:05 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Squad.hpp"
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int
main(void)
{
    ISquad* vlc = new Squad;
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;

    vlc->push(bob);
    vlc->push(jim);

    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }

    vlc->getUnit(0)->battleCry();
    vlc->getUnit(1)->battleCry();
    vlc->getUnit(0)->rangedAttack();
    vlc->getUnit(1)->rangedAttack();
    vlc->getUnit(0)->meleeAttack();
    vlc->getUnit(1)->meleeAttack();

    delete vlc;

    return (0);
}
