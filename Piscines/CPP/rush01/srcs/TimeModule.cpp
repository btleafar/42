/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:47 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:48 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeModule.hpp"

TimeModule::TimeModule(void)
{
    return ;
}

TimeModule::TimeModule(const TimeModule &src)
{
    *this = src;
    return ;
}

TimeModule::~TimeModule(void)
{
    return ;
}

TimeModule
&TimeModule::operator= (const TimeModule &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}
