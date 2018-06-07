/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:14:37 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/14 21:14:38 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "easyfind.hpp"

void
testValue(int val)
{
    std::list<int>    lst;

    lst.push_back(4);
    lst.push_back(8);
    lst.push_back(15);
    lst.push_back(16);
    lst.push_back(23);
    lst.push_back(42);

    std::cout << val << " -> ";
    try
    {
        easyfind<std::list<int>> (lst, val);
    }
    catch (std::string str)
    {
        std::cout << str << std::endl;
    }
}

int
main(void)
{
    testValue(1);
    testValue(4);
    testValue(16);
    testValue(29);
    testValue(42);
    return (0);
}
