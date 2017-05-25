/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:00:02 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/17 20:00:05 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_memmove - Copy one area of memory to another
** @dst: Where to copy to
** @src: Where to copy from
** @len: The size of the area.
**
** Unlike ft_memcpy(), ft_memmove() copes with overlapping areas.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	unsigned const char	*s;

	tmp = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (dst <= src)
	{
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += len;
		s += len;
		while (len--)
			*--tmp = *--s;
	}
	return ((void *)dst);
}
