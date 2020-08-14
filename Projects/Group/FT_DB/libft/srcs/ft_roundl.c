/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:26:59 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:49:52 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Need not raise the "inexact" floating-point exception for non-integer
** arguments that round to within the range of the return type.
*/

long double		ft_roundl(long double x)
{
	return ((long int)(x + 0.5));
}
