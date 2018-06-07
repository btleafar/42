/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:28:15 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:28:16 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Peon.hpp"
#include "Victim.hpp"
#include "Sorcerer.hpp"

int
main(void)
{
    // Declarations
    std::cout << "~~ Declarations ~~" << std::endl;
    Sorcerer  robert("Robert", "the Magnificent");
    Victim    jim("Jimmy");
    Peon      joe("Joe");

    // Separator (newline)
    std::cout << std::endl;

    // Messages
    std::cout << robert << std::endl << jim << std::endl << joe << std::endl;

    // Polymorphism
    robert.polymorph(jim);
    std::cout << std::endl;
    robert.polymorph(joe);
    std::cout << std::endl;

    return (0);
}
