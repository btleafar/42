/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hypot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:26:27 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:01:07 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Computes the sqrt(x*x+y*y) without undue overflow or underflow.
*/

double		ft_hypot(double x, double y)
{
	return (ft_sqrt((x * x) + (y * y)));
}
