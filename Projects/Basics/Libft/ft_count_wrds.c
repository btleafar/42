/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wrds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:12:58 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/25 17:13:01 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_wrds(const char *s, char c)
{
	int		i;
	int		count;
	int		has_word;

	i = 0;
	count = 0;
	while (s[i])
	{
		has_word = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			has_word = 1;
			i++;
		}
		while (s[i] == c)
			i++;
		if (has_word)
			count++;
	}
	return (count);
}
