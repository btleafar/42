/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:39 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule(void)
{
    return ;
}

OSInfoModule::OSInfoModule(const OSInfoModule &src)
{
    *this = src;
    return ;
}

OSInfoModule::~OSInfoModule(void)
{
    return ;
}

OSInfoModule
&OSInfoModule::operator= (const OSInfoModule &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}
