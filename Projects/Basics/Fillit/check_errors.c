/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:55:53 by rtorres-          #+#    #+#             */
/*   Updated: 2016/12/15 16:55:53 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_elems(char *input)
{
	int i;

	i = 0;
	if (input[i] == '\0')
		return (-1);
	while (input[i] != '\0')
	{
		if (input[i] == '#' || input[i] == '\n' || input[i] == '.')
			i++;
		else
			return (-1);
	}
	return (0);
}

int		check_new_lines(char *input)
{
	int i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '#' || input[i] == '.')
			i++;
		else if (input[i] == '\n')
		{
			if ((input[i - 1] == '#' || input[i - 1] == '.') &&
			(input[i + 1] == '#' || input[i + 1] == '.'))
				i++;
			else if ((input[i + 1] == '\n' || input[i + 1] == '\0') &&
			(input[i - 1] == '#' || input[i - 1] == '.'))
				i++;
			else if (input[i - 1] == '\n' && (input[i + 1] == '.' ||
			input[i + 1] == '#'))
				i++;
			else
				return (-1);
		}
		else
			return (-1);
	}
	return (0);
}

int		count_the_lines(char *input)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\n')
			line++;
		i++;
	}
	if (((line + 1) % 5 != 0) || ((line + 1) / 5) > 26)
		return (-1);
	return (0);
}

int		check_dot_pounds(char *input)
{
	int i;
	int pound;
	int valid;
	int dot;

	i = 0;
	while (input[i] != '\0')
	{
		dot = 0;
		pound = 0;
		valid = 20;
		while (valid != 0)
		{
			if (input[i] == '#')
				pound++;
			if (input[i] == '.')
				dot++;
			valid--;
			i++;
		}
		if (pound != 4 || dot != 12)
			return (-1);
		i++;
	}
	return (0);
}

int		check_orderoffig(char *input)
{
	int i;
	int elem;

	i = 0;
	elem = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '#' || input[i] == '.')
		{
			elem++;
			i++;
		}
		if (input[i] == '\n' && elem == 4)
		{
			elem = 0;
			i++;
		}
		if (input[i] == '\n' && input[i - 1] == '\n' && (input[i + 1] == '.' ||
		input[i + 1] == '#'))
			i++;
		if (input[i] == '\n' && elem != 4)
			return (-1);
	}
	return (0);
}
