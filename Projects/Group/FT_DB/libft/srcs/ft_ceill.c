/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:26:47 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:02:52 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns in long, the smallest integral value greater than or equal to x.
*/

long double		ft_ceill(long double x)
{
	if (x < 0)
		return ((long int)x);
	return (((long int)x) + 1);
}
