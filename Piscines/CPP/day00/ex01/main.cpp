/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 20:23:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/03 20:23:38 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

/*
** Shows the menu with the available commands.
*/

static void
menu(void)
{
	std::cout << "A poor excuse of a phonebook ;)" << std::endl;
    std::cout << " ____ _  _  __  __ _ ____ ____  __   __ __ _ \n";
    std::cout << "(  _ / )( \\/  \\(  ( (  __(  _ \\/  \\ /  (  / )\n";
    std::cout << " ) __) __ (  O /    /) _) ) _ (  O (  O )  ( \n";
    std::cout << "(__) \\_)(_/\\__/\\_)__(____(____/\\__/ \\__(__\\_)\n";
    std::cout << std::endl;
    std::cout << "Available commands:" << std::endl;
    std::cout << "ADD" << std::endl;
    std::cout << "SEARCH" << std::endl;
    std::cout << "EXIT" << std::endl;
    std::cout << std::endl;
}

/*
** Get things rolling.
*/

int
main(void)
{
    int             contact_index;
    Contact         phonebook[MAX_CONTACTS];
    std::string     command;

    menu();
    contact_index = 0;
    while (1)
    {
        getline(std::cin, command, '\n');
        if (command == "ADD")
        {
            if (contact_index < MAX_CONTACTS)
                phonebook[contact_index++] = addContact();
            else
                std::cout << "Phonebook is full! Brace yourself." << std::endl;
        }
        else if (command == "SEARCH")
        {
            if (contact_index > 0)
                showPhonebook(phonebook, contact_index);
            else
                std::cout << "Phonebook is empty. :O" << std::endl;
        }
        else if (command == "EXIT")
        {
            break ;
        }
    }
    return (0);
}
