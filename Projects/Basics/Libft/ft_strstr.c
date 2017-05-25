/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 01:40:02 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/13 02:10:49 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strstr - Find the first substring in a %NUL terminated string
** @big: The string to be searched
** @little: The string to search for
*/

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*str;
	const char	*to_find;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		str = big;
		to_find = little;
		while (*str && *to_find)
			if (*str++ != *to_find)
				break ;
			else
				to_find++;
		if (*to_find == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
