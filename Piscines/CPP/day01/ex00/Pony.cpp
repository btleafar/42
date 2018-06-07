/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 16:13:00 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/04 16:13:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void)
{
    return ;
}

Pony::~Pony(void)
{
    return ;
}

void
Pony::setName(std::string str)
{
    this->_name = str;
    return ;
}

void
Pony::setMark(std::string str)
{
    this->_mark = str;
    return ;
}

void
Pony::setAge(std::string str)
{
    this->_age = str;
    return ;
}

void
Pony::setColor(std::string str)
{
    this->_color = str;
    return ;
}

std::string
Pony::getName(void)
{
    return (this->_name);
}

std::string
Pony::getMark(void)
{
    return (this->_mark);
}

std::string
Pony::getAge(void)
{
    return (this->_age);
}

std::string
Pony::getColor(void)
{
    return (this->_color);
}
