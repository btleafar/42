/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:52:26 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:52:27 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Checks if the number base is valid.
*/

static int	check_base(char *base)
{
	int		i;
	int		z;

	i = 0;
	z = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		while (base[z])
			if (base[i] == base[z++])
				return (0);
		i += 1;
	}
	return (1);
}

/*
** Displays a number in a base system onscreen.
*/

void		ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		size;
	int		n[10];

	i = 0;
	size = 0;
	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	while (base[size])
		size += 1;
	while (nbr)
	{
		n[i] = nbr % size;
		nbr /= size;
		i += 1;
	}
	while (i > 0)
		write(1, &base[n[--i]], 1);
}
