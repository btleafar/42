/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 20:58:09 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/18 20:58:11 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*end_of_numbers(const char **str)
{
	const char *s;

	while (**str == '0')
		(*str)++;
	s = *str;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			break ;
		s++;
	}
	return (s);
}

int					ft_atoi(const char *str)
{
	const char			*end;
	const char			*s;
	unsigned long long	result;
	int					sign;

	while (SPACES(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	end = end_of_numbers(&str);
	result = 0;
	s = str;
	while (s < end)
	{
		result = result * 10LL + (unsigned long long)(*s - '0');
		s++;
	}
	if ((end - str) > 19 || result >= 9223372036854775808uLL)
		return ((sign == 1) ? -1 : 0);
	return (sign * (int)result);
}
