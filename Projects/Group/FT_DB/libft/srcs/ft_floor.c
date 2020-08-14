/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:26:06 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:01:15 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the largest integral value less than or equal to x
*/

double		ft_floor(double x)
{
	if (x > 0)
		return ((int)x);
	return (((int)x) - 1);
}
