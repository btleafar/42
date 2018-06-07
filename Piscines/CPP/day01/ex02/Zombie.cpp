/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:06:21 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 03:06:22 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string t, std::string n): _type(t), _name(n)
{
    return ;
}
Zombie::~Zombie(void)
{
    return ;
}

std::string
Zombie::announce(void)
{
    std::string format;
    std::string message;

    format = "<" + this->_name + " (" + this->_type + ")> ";
    message = "Braiiiiiiinnnssss...";
    return (format + message);
}
