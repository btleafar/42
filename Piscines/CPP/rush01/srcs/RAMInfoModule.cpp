/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfoModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:43 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:44 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMInfoModule.hpp"

RAMInfoModule::RAMInfoModule(void)
{
    return ;
}

RAMInfoModule::RAMInfoModule(const RAMInfoModule &src)
{
    *this = src;
    return ;
}

RAMInfoModule::~RAMInfoModule(void)
{
    return ;
}

RAMInfoModule
&RAMInfoModule::operator= (const RAMInfoModule &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}
