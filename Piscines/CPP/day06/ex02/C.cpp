/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:59:20 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 11:59:20 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(void)
{
    return ;
}

C::C(const C &src)
{
    *this = src;
    return ;
}

C::~C(void)
{
    return ;
}

C
&C::operator= (const C &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}
