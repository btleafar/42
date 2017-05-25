/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:50:12 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/15 00:50:15 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strnstr - Find the first substring in a length-limited string
** @big: The string to be searched
** @little: The string to search for
** @len: the maximum number of characters to search
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	if (!*big && !*little)
		return ("");
	while (*big)
	{
		if (l < ft_strlen(little))
			break ;
		if (ft_strlen(big) < ft_strlen(little))
			break ;
		if (ft_memcmp(big, little, ft_strlen(little)) == 0)
			return ((char*)big);
		l--;
		big++;
	}
	return (NULL);
}
