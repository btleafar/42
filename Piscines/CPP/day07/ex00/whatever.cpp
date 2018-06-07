/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:02:44 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/13 20:02:45 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

template <typename T>
void
swap(T &a, T &b)
{
    T   tmp = a;
    a = b;
    b = tmp;
    return ;
}

template <typename T>
T const
&min(T const &a, T const &b)
{
    return (b > a ? a : b);
}

template <typename T>
T const
&max(T const &a, T const &b)
{
    return (b > a ? b : a);
}

int
main(void)
{
    int   a = 2;
    int   b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    return (0);
}
