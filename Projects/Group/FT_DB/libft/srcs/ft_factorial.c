/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:36:15 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:01:42 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Calculates the product of all the positive integers from 1 to a given number.
*/

size_t		ft_factorial(unsigned int nbr)
{
	if (nbr >= 1)
		return (nbr * ft_factorial(nbr - 1));
	if (!nbr)
		return (1);
	return (0);
}
