/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumez-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:26:20 by iumez-er          #+#    #+#             */
/*   Updated: 2016/12/19 14:26:23 by iumez-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITESPACE1 (str[i] == '\t' || str[i] == ' ' ||  str[i] == '\n')
#define WS2 (str[i] == '\r' || str[i] == '\v' || str[i] == '\f')

#include "fillit.h"

static	int	determine_sign(const char *str)
{
	int i;

	i = 0;
	while (WHITESPACE1 || WS2)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		if (str[i] == '+')
			return (1);
	}
	return (1);
}

static	int	find_start(const char *str, int i)
{
	while (WHITESPACE1 || WS2)
		i++;
	if ((str[i] == '+' || str[i] == '-'))
		i++;
	if (str[i] != '\0')
	{
		while (str[i] == '0')
			i++;
		return (i);
	}
	else
		return (-3);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;
	int number;

	sign = determine_sign(str);
	i = find_start(str, 0);
	if (i >= 0)
	{
		number = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				number = number * 10 + str[i] - '0';
				i++;
			}
			else
				return (sign * number);
		}
		return (sign * number);
	}
	else
		return (0);
}
