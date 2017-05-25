/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:21:46 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/11 23:20:08 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncpy - Copy a length-limited, C-string
** @dst: Where to copy the string to
** @src: Where to copy the string from
** @len: The maximum number of bytes to copy
**
** The result is not %NUL-terminated if the source exceeds
** @len bytes.
**
** In the case where the length of @src is less than  that  of
** len, the remainder of @dst will be padded with %NUL.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*d;
	size_t	l;

	d = dst;
	l = 0;
	while (*src != '\0' && l < len)
	{
		*dst++ = *src++;
		l++;
	}
	while (l < len)
	{
		*dst++ = '\0';
		l++;
	}
	return (d);
}
