/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:15:41 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:39:21 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates with malloc(), and returns an array of “fresh” strings
** (all ending with ’\0’, including the array itself) obtained by spliting
** the string s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
** Example : ft_strsplit("*hello*fellow***students*", ’*’)
** returns the array ["hello", "fellow", "students"].
*/

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**w;

	i = 0;
	k = 0;
	if (!s || !(w = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (i < ft_wordcount(s, c))
	{
		if (!(w[i] = (char *)malloc(sizeof(char) * (ft_wordlen(&s[k], c) + 1))))
			return (NULL);
		j = 0;
		while (s[k] == c)
			k += 1;
		while (s[k] != c && s[k])
			w[i][j++] = s[k++];
		w[i][j] = '\0';
		i += 1;
	}
	w[i] = NULL;
	return (w);
}
