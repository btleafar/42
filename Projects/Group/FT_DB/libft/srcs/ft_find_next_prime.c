/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 23:16:39 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:01:27 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the next prime number greater or equal to the number
** given as argument.
*/

size_t		ft_find_next_prime(unsigned int nb)
{
	nb += 1;
	while (!ft_isprime(nb))
		nb += 1;
	return (nb);
}
