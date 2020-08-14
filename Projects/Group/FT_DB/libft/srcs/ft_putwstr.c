/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 07:52:18 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:50:31 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function begins printing from the address specified (wcs) until it
** reaches the terminating null wide character.
** This terminating null wide character is not printed to the standard output.
*/

int		ft_putwstr(wchar_t *wcs)
{
	int		len;

	len = 0;
	while (*wcs)
	{
		ft_putwchar(*wcs);
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
