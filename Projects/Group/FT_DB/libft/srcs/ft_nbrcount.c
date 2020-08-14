/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:56:04 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:56:05 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the numbers found in a string (using the variable c as a separator).
*/

size_t		ft_nbrcount(const char *s, char c)
{
	size_t	i;
	size_t	nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (s[i] != c)
			nbr += 1;
		while (s[i] != c && ft_isdigit(s[i]) && s[i + 1])
			i += 1;
		i += 1;
	}
	return (nbr);
}
