/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPrecision.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 08:57:06 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 08:57:06 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstring>

int
getPrecision(char *str)
{
    unsigned int     before;
    unsigned int     after;

    before = 0;
    while (str[before] && str[before] != '.')
    {
        before += 1;
    }
    after = before + 1;
    while (str[after] && isdigit(str[after]))
    {
        after += 1;
    }
    after -= before;
    return ((strlen(str) == before || after == 1) ? 1 : after - 1);
}
