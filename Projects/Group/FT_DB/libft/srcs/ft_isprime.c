/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:28:58 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:00:12 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the number is a prime number.
*/

int		ft_isprime(long unsigned int nbr)
{
	unsigned long int	i;

	if (!nbr)
		return (0);
	i = 1;
	while (++i <= nbr)
	{
		if (!(nbr % i))
			break ;
	}
	if (i == nbr)
		return (1);
	return (0);
}
