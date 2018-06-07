/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 02:55:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 02:55:39 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void
memoryLeak(void)
{
    std::string*    panthere = new std::string("String panthere");
    std::cout << *panthere << std::endl;
    delete panthere;
}
