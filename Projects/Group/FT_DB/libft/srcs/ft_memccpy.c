/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:57:30 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:57:32 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops and a pointer to the byte after the copy of c in the
** string dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return (&((unsigned char *)dst)[i + 1]);
		i += 1;
	}
	return (NULL);
}
