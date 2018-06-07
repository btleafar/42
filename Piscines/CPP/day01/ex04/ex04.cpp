/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 05:56:36 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 05:56:37 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int
main(void)
{
    std::string     str = "HI THIS IS BRAIN";
    std::string     *ptr = &str;
    std::string     &ref = str;

    std::cout << "String    : " << str << std::endl;
    std::cout << "Pointer   : " << *ptr << std::endl;
    std::cout << "Reference : " << ref << std::endl;
    return (0);
}
