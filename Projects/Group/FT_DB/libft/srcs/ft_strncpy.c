/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:32:28 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:40:15 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy at most len characters from src into dst.
** If src is less than len characters long, the remainder of dst is filled
** with `\0' characters. Otherwise, dst is not terminated.
*/

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
