/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 08:26:28 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 08:26:29 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "convert.h"
#include "ScalarConversion.hpp"

int
main(int argc, char *argv[])
{
    double              value;
    int                 precision;
    ScalarConversion    scalar;

    for (int i = 1; i < argc; i += 1)
    {
        std::cout << "string : " << argv[i] << std::endl;
        precision = getPrecision(argv[i]);
        value = atof(argv[i]);
        checkChar(scalar, value);
        checkInt(scalar, value);
        checkDouble(scalar, value, precision);
        checkFloat(scalar, value, precision);
        std::cout << std::endl;
    }
    return (0);
}
