/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converted_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumez-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:03:25 by iumez-er          #+#    #+#             */
/*   Updated: 2016/12/03 13:08:00 by iumez-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*convert_str(char *str, int sqsize)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = (char *)malloc(sizeof(char) * sqsize + 1);
	if (!ptr)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
		ptr[j++] = str[i++];
	while (j < sqsize)
		ptr[j++] = '0';
	ptr[j] = '\0';
	return (ptr);
}

int		ft_iterative_power(int base, int power)
{
	int result;

	if (power == 0 || base == 1)
		return (1);
	else if (power < 0 || base < 0)
		return (0);
	else if (power > 0)
	{
		result = 1;
		while (power > 0)
		{
			result *= base;
			power--;
		}
		return (result);
	}
	return (0);
}

int		ft_bi_2_int(char *str)
{
	int	bitrep;
	int i;
	int n;

	bitrep = 0;
	i = 0;
	n = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[n] == '1')
			bitrep += ft_iterative_power(2, i - 1);
		n++;
		i--;
	}
	return (bitrep);
}
