/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:55:32 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:55:34 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns in long, +-infinity and raises the "divide-by-zero" floating-point
** exception for y an odd integer < 0.
*/

long double		ft_powl(long double x, long int y)
{
	long double z;

	z = 1.0;
	while (y > 0)
	{
		while (!(y & 1))
		{
			y >>= 2;
			x *= x;
		}
		--y;
		z = x * z;
	}
	return (z);
}
