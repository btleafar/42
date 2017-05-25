/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 23:58:07 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/13 23:58:10 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strrchr - Find the last occurrence of a character in a string
** @s: The string to be searched
** @c: The character to search for
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *str;

	str = s;
	while (*str)
		str++;
	if (c == 0)
		return ((char *)str);
	while (str > s)
	{
		str--;
		if (((unsigned char)*str) == c)
			return ((char *)str);
	}
	return (0);
}
