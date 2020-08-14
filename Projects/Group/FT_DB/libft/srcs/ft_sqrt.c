/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:53:46 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:49:35 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compute the non-negative square root of x.
** If x is negative, the function wil return zero (0).
*/

double		ft_sqrt(double x)
{
	double	i;

	i = 1.0;
	if (x < 0)
		return (0);
	while (i * i < x)
		i += 1;
	return (i);
}
