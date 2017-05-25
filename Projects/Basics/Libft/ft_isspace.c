/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:27:39 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/19 16:27:43 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**For the "C" locale, white-space characters are any of:
**' '	(0x20)	space (SPC)
**'\t'	(0x09)	horizontal tab (TAB)
**'\n'	(0x0a)	newline (LF)
**'\v'	(0x0b)	vertical tab (VT)
**'\f'	(0x0c)	feed (FF) == '\12'
**'\r'	(0x0d)	carriage return (CR)
**
** Another way to return the same result is:
** return ((9 <= c && c <= 13) || c == 32);
*/

#include "libft.h"

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\12');
}
