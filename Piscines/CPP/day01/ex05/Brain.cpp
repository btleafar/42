/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:11:47 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:11:48 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    setAddress();
    return ;
}

Brain::~Brain(void)
{
    return ;
}

void
Brain::setAddress(void)
{
    std::stringstream   buff;

    buff << this;
    this->_address = buff.str();
    return ;
}

std::string
Brain::getAddress(void)
{
    return (this->_address);
}

std::string
Brain::identify(void)
{
    return (this->getAddress());
}
