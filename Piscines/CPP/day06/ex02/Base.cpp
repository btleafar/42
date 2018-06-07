/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:59:39 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 11:59:40 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base(void)
{
    return ;
}

Base::Base(const Base &src)
{
    *this = src;
    return ;
}

Base::~Base(void)
{
    return ;
}

Base
&Base::operator= (const Base &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}
