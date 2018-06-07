/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:56 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/11 20:16:56 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

static void
checkBureaucrat(Bureaucrat test, int min, int max)
{
    try
    {
        for(int i = min; i <= max; i++)
        {
            test.setGrade(i);
            //test.incrementGrade();
            //test.decrementGrade();
            std::cout << test << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

int
main(void)
{
    Bureaucrat    test("Marvin", 42);

    checkBureaucrat(test, test.getGrade(), 150);
    return (0);
}
