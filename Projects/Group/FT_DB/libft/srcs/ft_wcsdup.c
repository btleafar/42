/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 07:47:26 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:36:34 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates sufficient memory for a copy of the wide string src, does the copy,
** and returns a pointer to it.
*/

wchar_t		*ft_wcsdup(wchar_t *src)
{
	int		len;
	wchar_t	*dst;

	len = ft_wcslen(src) + sizeof(wchar_t);
	dst = ft_memalloc(sizeof(wchar_t) * len);
	if (dst)
		ft_wcscpy(dst, src);
	return (dst);
}
