/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:25:33 by rtorres-          #+#    #+#             */
/*   Updated: 2016/12/15 11:12:36 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*tetris_shape(int i, char *s)
{
	int offset;

	offset = i / 21;
	if (s[i + 1] == '#')
	{
		s[i + 1] = 'x';
		s = tetris_shape(i + 1, s);
	}
	if (i - 1 >= offset * 21 && s[i - 1] == '#')
	{
		s[i - 1] = 'x';
		s = tetris_shape(i - 1, s);
	}
	if (i + 5 <= (offset + 1) * 21 && s[i + 5] == '#')
	{
		s[i + 5] = 'x';
		s = tetris_shape(i + 5, s);
	}
	if (i - 5 >= i % 20 && s[i - 5] == '#')
	{
		s[i - 5] = 'x';
		s = tetris_shape(i - 5, s);
	}
	return (s);
}

static int	ft_count_x(char *s)
{
	int res;

	res = 0;
	while (*s)
	{
		if (*s == 'x')
			res++;
		s++;
	}
	return (res);
}

int			check_in_pattern(char *s)
{
	int i;
	int count_x;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '#')
			i++;
		else
		{
			if (s[i] == '#')
				s[i] = 'x';
			s = tetris_shape(i, s);
			count_x = ft_count_x(s);
			if (count_x % 4 != 0)
				return (-1);
		}
	}
	while (*s)
	{
		if (*s == 'x')
			*s = '#';
		s++;
	}
	return (0);
}

void		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void		check_matrix(char *input)
{
	if (valid_elems(input) == -1 || check_orderoffig(input) == -1 ||
	check_new_lines(input) == -1 || check_dot_pounds(input) == -1 ||
	count_the_lines(input) == -1 || check_in_pattern(input) == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
}
