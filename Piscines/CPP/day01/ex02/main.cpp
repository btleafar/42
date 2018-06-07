/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:26:32 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 03:26:32 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int
main(void)
{
    Zombie      *zombie_1;
    Zombie      *zombie_2;
    ZombieEvent event;

    event.setZombieType("trolo");
    zombie_1 = event.randomChump();
    std::cout << zombie_1->announce() << std::endl;
    delete zombie_1;
    event.setZombieType("macho");
    zombie_2 = event.randomChump();
    std::cout << zombie_2->announce() << std::endl;
    delete zombie_2;
    return (0);
}
