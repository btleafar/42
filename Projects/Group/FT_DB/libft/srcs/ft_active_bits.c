/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:27:38 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:04:10 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of active bits in the int passed as argument.
*/

size_t	ft_active_bits(int value)
{
	size_t	bits;

	bits = 0;
	while (value > 0)
	{
		if ((value & 1) == 1)
			bits += 1;
		value >>= 1;
	}
	return (bits);
}
