/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:34 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:35 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameModule.hpp"

HostnameModule::HostnameModule(void)
{
    return ;
}

HostnameModule::HostnameModule(const HostnameModule &src)
{
    *this = src;
    return ;
}

HostnameModule::~HostnameModule(void)
{
    return ;
}

HostnameModule
&HostnameModule::operator= (const HostnameModule &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}
