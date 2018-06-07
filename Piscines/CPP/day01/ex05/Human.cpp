/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:12:00 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:12:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
    return ;
}
Human::~Human(void)
{
    return ;
}

Brain
Human::getBrain(void)
{
    return (this->_brain);
}

std::string
Human::identify(void)
{
    return (this->_brain.identify());
}
