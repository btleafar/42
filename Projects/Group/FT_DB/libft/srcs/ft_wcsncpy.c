/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 07:45:29 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:36:11 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy at most len wide characters from src into dst.
** If src is less than len characters long, the remainder of dst is filled
** with `\0' characters. Otherwise, dst is not terminated.
*/

wchar_t		*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (len < n)
	{
		len += ft_wclen(src[i]);
		if (len > n)
			break ;
		dst[i] = src[i];
		dst[++i] = L'\0';
	}
	return (dst);
}
