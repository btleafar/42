/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 08:26:16 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 08:26:17 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(void)
{
    return ;
}

ScalarConversion::ScalarConversion(const ScalarConversion &src)
{
    *this = src;
    return ;
}

ScalarConversion::~ScalarConversion(void)
{
    return ;
}

ScalarConversion
&ScalarConversion::operator= (const ScalarConversion &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

char
ScalarConversion::convertToChar(double d)
{
    char    c;

    if (std::isnan(d) == true)
    {
        throw (ScalarConversion::Impossible());
    }
    c = static_cast<char>(d);
    if (std::isprint(c) == false)
    {
        throw (ScalarConversion::NonDisplayable());
    }
    return (c);
}

int
ScalarConversion::convertToInt(double d)
{
    if (std::isnan(d) == true || std::isinf(d) == true)
    {
        throw (ScalarConversion::Impossible());
    }
    if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
    {
        throw (ScalarConversion::Impossible());
    }
    return (static_cast<int>(d));
}

float
ScalarConversion::convertToFloat(double d)
{
    return (static_cast<float>(d));
}

double
ScalarConversion::convertToDouble(double d)
{
     return (static_cast<double>(d));
}

ScalarConversion::
NonDisplayable::NonDisplayable(void)
{
    return ;
}

ScalarConversion::
NonDisplayable::NonDisplayable(ScalarConversion::NonDisplayable const &src)
{
    *this = src;
    return ;
}

ScalarConversion::
NonDisplayable::~NonDisplayable(void) throw()
{
    return ;
}

ScalarConversion::NonDisplayable
&ScalarConversion::NonDisplayable::\
operator= (const ScalarConversion::NonDisplayable &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

const char
*ScalarConversion::NonDisplayable::what(void) const throw()
{
    return("Non displayable");
}

ScalarConversion::
Impossible::Impossible(void)
{
    return ;
}

ScalarConversion::
Impossible::Impossible(ScalarConversion::Impossible const &src)
{
    *this = src;
    return ;
}

ScalarConversion::Impossible::~Impossible(void) throw()
{
    return ;
}

ScalarConversion::Impossible
&ScalarConversion::Impossible::
operator= (const ScalarConversion::Impossible &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

const char
*ScalarConversion::Impossible::what(void) const throw()
{
    return("impossible");
}
