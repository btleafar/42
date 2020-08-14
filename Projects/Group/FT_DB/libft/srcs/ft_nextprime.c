/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:55:47 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:55:49 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Gives the smallest prime large number after nbr.
*/

long unsigned int	ft_nextprime(long unsigned int nbr)
{
	nbr += 1;
	while (!ft_isprime(nbr))
	{
		nbr++;
	}
	return (nbr);
}
