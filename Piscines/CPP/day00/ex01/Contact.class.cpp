/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:48:01 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/04 15:48:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) { return ; }
Contact::~Contact(void) { return ; }

std::string Contact::getFirstName(void)
{
    return (this->_firstName);
}

std::string Contact::getLastName(void)
{
    return (this->_lastName);
}

std::string Contact::getNickname(void)
{
    return (this->_nickname);
}

std::string Contact::getLogin(void)
{
    return (this->_login);
}

std::string Contact::getPostalAddress(void)
{
    return (this->_postalAddress);
}

std::string Contact::getEmailAddress(void)
{
    return (this->_emailAdress);
}

std::string Contact::getPhoneNumber(void)
{
    return (this->_phoneNumber);
}

std::string Contact::getBirthdayDate(void)
{
    return (this->_birthdayDate);
}

std::string Contact::getFavoriteMeal(void)
{
    return (this->_favoriteMeal);
}

std::string Contact::getUnderWearColor(void)
{
    return (this->_underwearColor);
}

std::string Contact::getDarkestSecret(void)
{
    return (this->_darkestSecret);
}

void        Contact::setFirstName(std::string str)
{
    this->_firstName = str;
    return ;
}

void        Contact::setLastName(std::string str)
{
    this->_lastName = str;
    return ;
}

void        Contact::setNickname(std::string str)
{
    this->_nickname = str;
    return ;
}

void        Contact::setLogin(std::string str)
{
    this->_login = str;
    return ;
}

void        Contact::setPostalAddress(std::string str)
{
    this->_postalAddress = str;
    return ;
}

void        Contact::setEmailAddress(std::string str)
{
    this->_emailAdress = str;
    return ;
}

void        Contact::setPhoneNumber(std::string str)
{
    this->_phoneNumber = str;
    return ;
}

void        Contact::setBirthdayDate(std::string str)
{
    this->_birthdayDate = str;
    return ;
}

void        Contact::setFavoriteMeal(std::string str)
{
    this->_favoriteMeal = str;
    return ;
}

void        Contact::setUnderwearColor(std::string str)
{
    this->_underwearColor = str;
    return ;
}

void        Contact::setDarkestSecret(std::string str)
{
    this->_darkestSecret = str;
    return ;
}
