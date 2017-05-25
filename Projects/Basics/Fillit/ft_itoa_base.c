/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumez-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:11:59 by iumez-er          #+#    #+#             */
/*   Updated: 2016/11/24 22:12:00 by iumez-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	determine_num_digits(int value, int base)
{
	int	i;

	i = 1;
	while (value / base)
	{
		value = value / base;
		i++;
	}
	if (base == 10)
	{
		if (value < 0)
			i++;
	}
	return (i);
}

static	int	pos_mod(int value, int base)
{
	int	mod;

	mod = value % base;
	if (mod < 0)
		mod *= -1;
	return (mod);
}

char		*ft_itoa_base(int value, int base)
{
	const	char	*a;
	int				nd;
	char			*ptr;

	a = "0123456789ABCDEF";
	if (base != 10)
		value = (unsigned int)value;
	nd = determine_num_digits(value, base);
	ptr = (char *)malloc(sizeof(char) * (nd + 1));
	if (!ptr)
		return (0);
	ptr[nd] = '\0';
	while (value / base)
	{
		ptr[nd - 1] = a[pos_mod(value, base)];
		value = value / base;
		nd--;
	}
	ptr[nd - 1] = a[pos_mod(value, base)];
	if (base == 10 && value < 0)
		ptr[0] = '-';
	return (ptr);
}
