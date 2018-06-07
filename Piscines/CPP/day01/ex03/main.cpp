/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 05:39:09 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 05:39:09 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

int
main(void)
{
    ZombieHorde z1 = ZombieHorde(20);
    ZombieHorde z2 = ZombieHorde();
    z1.announce();
    z2.announce();
    return (0);
}
