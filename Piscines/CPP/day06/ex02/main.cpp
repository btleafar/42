/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:59:48 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 11:59:49 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base
*generate(void)
{
    int     i;
    Base    *randomBase;

    i = rand() % 3;
    if (i == 0)
    {
        std::cout << "Class A has been generated!" << std::endl;
        return (randomBase = new A());
    }
    else if (i == 1)
    {
        std::cout << "Class B has been generated!" << std::endl;
        return (randomBase = new B());
    }
    std::cout << "Class c has been generated!" << std::endl;
    return (randomBase = new C());
}

void
identify_from_pointer(Base *ptr)
{
    A   *cl_a = dynamic_cast<A*>(ptr);
    if (cl_a)
    {
        std::cout << "A identified from pointer" << std::endl;
    }
    B   *cl_b = dynamic_cast<B*>(ptr);
    if (cl_b)
    {
        std::cout << "B identified from pointer" << std::endl;
    }
    C   *cl_c = dynamic_cast<C*>(ptr);
    if (cl_c)
    {
        std::cout << "C identified from pointer" << std::endl;
    }
}

void
identify_from_reference(Base &ptr)
{
    try
    {
        A   &cl_a = dynamic_cast<A&>(ptr);
        std::cout << "A identified from reference" << std::endl;
        static_cast<void>(cl_a);
    }
    catch (std::bad_cast &bc)
    {
        std::cout << "Failed to cast A" << std::endl;
    }
    try
    {
        B   &cl_b = dynamic_cast<B &>(ptr);
        std::cout << "B identified from reference" << std::endl;
        static_cast<void>(cl_b);
    }
    catch (std::bad_cast &bc)
    {
        std::cout << "Failed to cast B" << std::endl;
    }
    try
    {
        C   &cl_c = dynamic_cast<C &>(ptr);
        std::cout << "C identified from reference" << std::endl;
        static_cast<void>(cl_c);
    }
    catch (std::bad_cast &bc)
    {
        std::cout << "Failed to cast C" << std::endl;
    }
}

int
main(void)
{
    srand(time(NULL));
    Base    *ptr = generate();

    identify_from_pointer(ptr);
    identify_from_reference(*ptr);

    return (0);
}
