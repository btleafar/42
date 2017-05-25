/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:00:06 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/16 23:00:10 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memcpy - Copy one area of memory to another
** @dst: Where to copy to
** @src: Where to copy from
** @len: The size of the area.
**
** You should not use this function to access IO space, use memcpy_toio()
** or memcpy_fromio() instead.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp;
	const char	*s;

	tmp = dst;
	s = src;
	while (n--)
		*tmp++ = *s++;
	return (dst);
}
