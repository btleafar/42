/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfoModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:30 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:30 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUInfoModule.hpp"

CPUInfoModule::CPUInfoModule(void)
{
    return ;
}

CPUInfoModule::CPUInfoModule(const CPUInfoModule &src)
{
    *this = src;
    return ;
}

CPUInfoModule::~CPUInfoModule(void)
{
    return ;
}

CPUInfoModule
&CPUInfoModule::operator= (const CPUInfoModule &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}
