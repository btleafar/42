/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 05:07:58 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:41:12 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends the NULL-terminated string src to the end of dst.
** It will append at most size - strlen(dst) - 1 bytes, NULL-terminating
** the result.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && len < size)
		len += 1;
	i = len;
	while (src[len - i] && len + 1 < size)
	{
		dst[len] = src[len - i];
		len += 1;
	}
	if (i < size)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}
