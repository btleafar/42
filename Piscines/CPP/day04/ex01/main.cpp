/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:31:44 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:31:44 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"

int
main(void)
{
    Character *zaz = new Character("zaz");
    std::cout << *zaz;
    Enemy *b = new RadScorpion();
    Enemy *c = new RadScorpion();
    Enemy *d = new RadScorpion();
    AWeapon *pr = new PlasmaRifle();
    AWeapon *pf = new PowerFist();
    
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);
    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;

    zaz->attack(c);
    std::cout << *zaz;
    zaz->attack(c);
    std::cout << *zaz;
    zaz->attack(c);
    std::cout << *zaz;
    zaz->attack(c);
    std::cout << *zaz;
    zaz->attack(d);
    std::cout << *zaz;
    zaz->attack(d);
    std::cout << *zaz;
    zaz->attack(d);
    std::cout << *zaz;

    return (0);
}
