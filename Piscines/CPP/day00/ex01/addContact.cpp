/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 03:19:13 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/05 03:19:14 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

/*
** Asks for the info of a contact, and save that as a new contact.
*/

Contact
addContact(void)
{
    Contact     new_contact;
    std::string buffer;

    std::cout << "First name : ";
    std::cin >> buffer;
    new_contact.setFirstName(buffer);
    std::cout << "Last name : ";
    std::cin >> buffer;
    new_contact.setLastName(buffer);
    std::cout << "Nick name : ";
    std::cin >> buffer;
    new_contact.setNickname(buffer);
    std::cout << "Login : ";
    std::cin >> buffer;
    new_contact.setLogin(buffer);
    std::cout << "Postal Address : ";
    std::cin >> buffer;
    new_contact.setPostalAddress(buffer);
    std::cout << "Email Address : ";
    std::cin >> buffer;
    new_contact.setEmailAddress(buffer);
    std::cout << "Phone Number : ";
    std::cin >> buffer;
    new_contact.setPhoneNumber(buffer);
    std::cout << "Birthday : ";
    std::cin >> buffer;
    new_contact.setBirthdayDate(buffer);
    std::cout << "Favorite Meal : ";
    std::cin >> buffer;
    new_contact.setFavoriteMeal(buffer);
    std::cout << "Underwear Color : ";
    std::cin >> buffer;
    new_contact.setUnderwearColor(buffer);
    std::cout << "Darkest Secret : ";
    std::cin >> buffer;
    new_contact.setDarkestSecret(buffer);
    std::cout << std::endl << "Everything saved. Cool. :D" << std::endl;
    return (new_contact);
}
