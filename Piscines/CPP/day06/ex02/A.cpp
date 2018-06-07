/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:58:52 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 11:58:53 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(void)
{
    return ;
}

A::A(const A &src)
{
    *this = src;
    return ;
}

A::~A(void)
{
    return ;
}

A
&A::operator= (const A &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}
