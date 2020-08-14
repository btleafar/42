/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:59:06 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:59:07 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Gets the total size of a two dimensional array.
*/

static int	tab_size(char **tab)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 1;
	size = 0;
	while (tab && tab[j])
	{
		while (tab && tab[j][i])
			i += 1;
		size += i + 1;
		j += 1;
		i = 0;
	}
	size += j;
	return (size);
}

/*
** Merges the array given as a parameter into one single character string.
** The separation argument will serve as "glue" between elements.
*/

char		*ft_join(char **tab, char *sep)
{
	int		i;
	int		k;
	int		s;
	int		size;
	char	*str;

	i = 1;
	k = 0;
	s = 0;
	size = tab_size(tab);
	str = (char*)malloc(sizeof(char) * size + 1);
	while (s < (size - 1) && tab[i])
	{
		while (tab && tab[i][k])
			str[s++] = tab[i][k++];
		str[s++] = *sep;
		i += 1;
		k = 0;
	}
	str[s] = '\0';
	return (str);
}
