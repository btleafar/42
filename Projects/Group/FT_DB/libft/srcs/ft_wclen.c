/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 07:37:18 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:36:49 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Computes the length of the wide character wc.
*/

int		ft_wclen(wchar_t wc)
{
	int		len;

	len = 0;
	if (wc <= 0xFF)
		len = 1;
	else if (wc < 0x0800)
		len = 2;
	else if (wc < 0x010000)
		len = 3;
	else if (wc < 0x110000)
		len = 4;
	return (len);
}
