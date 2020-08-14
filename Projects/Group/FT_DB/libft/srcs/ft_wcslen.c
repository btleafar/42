/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 07:39:21 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:36:21 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Computes the length of the wide character string wcs.
*/

size_t	ft_wcslen(wchar_t *wcs)
{
	size_t	len;

	len = 0;
	while (*wcs)
	{
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
