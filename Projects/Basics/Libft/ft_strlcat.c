/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:17:52 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/11 23:15:05 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strlcat - Append a length-limited, C-string to another
** @dst: The string to be appended to
** @src: The string to append to it
** @size: The size of the destination buffer.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_sz;
	int		i;
	int		j;

	dst_sz = ft_strlen(dst);
	i = 0;
	j = 0;
	if (size > 0 && size > dst_sz)
	{
		i = dst_sz;
		while (src[j] && i < (int)size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = 0;
		return (dst_sz + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
