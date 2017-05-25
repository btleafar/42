/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:59:22 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/13 16:59:24 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strchr - Find the first occurrence of a character in a string
** @s: The string to be searched
** @c: The character to search for
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char *str;

	str = s;
	while (*str)
	{
		if (((unsigned char)*str) == c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (0);
}
