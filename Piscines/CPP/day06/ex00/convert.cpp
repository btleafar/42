/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 09:05:22 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 09:05:23 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

void
checkChar(ScalarConversion scalar, double value)
{
    try
    {
        std::cout << "char   : ";
        std::cout << "'" << scalar.convertToChar(value) << "'" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void
checkInt(ScalarConversion scalar, double value)
{
    try
    {
        std::cout << "int    : ";
        std::cout << scalar.convertToInt(value) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void
checkDouble(ScalarConversion scalar, double value, int precision)
{
    try
    {
        std::cout << "double : ";
        std::cout << std::setprecision(precision) \
        << std::fixed << scalar.convertToDouble(value) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void
checkFloat(ScalarConversion scalar, double value, int precision)
{
    try
    {
        std::cout << "float  : ";
        std::cout << std::setprecision(precision) \
        << std::fixed << scalar.convertToFloat(value) << "f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
