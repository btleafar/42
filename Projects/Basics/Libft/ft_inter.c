/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:22:26 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/26 16:22:28 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_inter takes two strings and displays, without doubles, the characters
** that appear in both strings, in the order they appear in the first
** one.
**
** The display will be followed by a \n.
*/

#include "libft.h"

static int		is_first(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (i == pos)
		return (1);
	return (0);
}

static int		is_instring(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (1);
}

void			ft_inter(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (is_first(s1, s1[i], i) && is_instring(s2, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
}
