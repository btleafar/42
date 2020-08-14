/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:27:32 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:49:24 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compute in long, the non-negative square root of x.
** If x is negative, the function wil return zero (0).
*/

long double		ft_sqrtl(long double x)
{
	long double	i;

	i = 1.0;
	if (x < 0)
		return (0);
	while (i * i < x)
		i += 1;
	return (i);
}
