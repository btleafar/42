/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:59:12 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 11:59:14 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(void)
{
    return ;
}

B::B(const B &src)
{
    *this = src;
    return ;
}

B::~B(void)
{
    return ;
}

B
&B::operator= (const B &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}
