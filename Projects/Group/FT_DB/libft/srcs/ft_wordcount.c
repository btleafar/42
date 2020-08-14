/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:15:41 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:35:35 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the words found in a string (using the variable c as a separator).
*/

size_t		ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
			w += 1;
		while (s[i] != c && s[i + 1])
			i += 1;
		i += 1;
	}
	return (w);
}
