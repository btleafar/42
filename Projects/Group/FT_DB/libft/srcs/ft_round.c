/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:26:13 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:49:59 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Raise the "inexact" floating-point exception for non-integer
** numeric arguments.
*/

double		ft_round(double x)
{
	return ((int)(x + 0.5));
}
