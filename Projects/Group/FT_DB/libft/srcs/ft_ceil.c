/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:25:56 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:02:56 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the smallest integral value greater than or equal to x.
*/

double		ft_ceil(double x)
{
	if (x < 0)
		return ((int)x);
	return (((int)x) + 1);
}
