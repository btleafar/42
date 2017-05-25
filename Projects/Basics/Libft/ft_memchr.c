/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:17:00 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/17 22:17:03 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_memchr - Find a character in an area of memory.
** @s: The memory area
** @c: The byte to search for
** @n: The size of the area.
**
** returns the address of the first occurrence of @c, or %NULL
** if @c is not found
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = (unsigned char *)s;
	while (n-- != 0)
	{
		if ((unsigned char)c == *p++)
			return (void *)(p - 1);
	}
	return (NULL);
}
