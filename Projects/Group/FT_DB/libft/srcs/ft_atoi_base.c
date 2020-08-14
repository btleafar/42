/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 04:48:29 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:09 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the number base is valid.
*/

static int	verify_nbr_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10)));
}

/*
** Converts the initial portion of a string pointed to the variable string, to
** an int representarion (type). The string is given as a number with a specific
** base, from binary to hexadecimal.
*/

int			ft_atoi_base(const char *str, int base)
{
	int		i;
	int		nbr;
	int		sign;

	if (!str || (base < 2 || base > 16))
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || \
		str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		str[i++] == '-' ? sign *= -1 : sign;
	while (str[i] && verify_nbr_base(str[i], base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * base) + (str[i] - '0');
		i += 1;
	}
	return (nbr * sign);
}
