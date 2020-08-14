/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separated_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:16:30 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:49:42 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter a list of "words" returns an array of strings.
** Each word is added to a string, separated by the parameter 'c', which
** is used to separate the words in the strings.
*/

char		*ft_separated_values(char **values, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	words;
	char	*separated;

	i = 0;
	k = 0;
	if (!(separated = (char *)malloc(sizeof(char) * ft_char_count(values) + 1)))
		return (NULL);
	words = ft_values_count(values) - 1;
	while (values[i] != NULL)
	{
		j = 0;
		while (values[i][j] != '\0')
			separated[k++] = values[i][j++];
		if (i < words)
			separated[k++] = c;
		i += 1;
	}
	separated[k] = '\0';
	return (separated);
}
