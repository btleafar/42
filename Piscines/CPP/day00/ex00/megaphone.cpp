/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:45:16 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/03 19:45:17 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// My coding style is based in C++ Coding Standard by Todd Hoff:
// http://maultech.com/chrislott/resources/cstyle/CppCodingStandard.htm

#include <cctype>
#include <string>
#include <iostream>

/*
** Capitalize all the arguments, and prints them by byte to the standard output.
*/

void
megaphone(int argc, char *argv[])
{
    for (int i = 1; i < argc; i += 1)
    {
        for (int j = 0; j < (int)strlen(argv[i]); j += 1)
        {
            std::cout << (char)toupper(argv[i][j]);
        }
    }
    std::cout << std::endl;
}

/*
** Get things rolling.
*/

int
main(int argc, char *argv[])
{
    if (argc > 1)
    {
        megaphone(argc, argv);
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return (0);
}
