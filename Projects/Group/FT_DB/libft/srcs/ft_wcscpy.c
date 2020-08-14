/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcscpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 07:41:57 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:36:42 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy the wide string src to dst (including the terminating `\0' character).
*/

wchar_t		*ft_wcscpy(wchar_t *dst, const wchar_t *src)
{
	size_t	i;

	i = 0;
	while ((dst[i] = src[i]) != L'\0')
		i += 1;
	return (dst);
}
