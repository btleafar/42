/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:15:41 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:35:20 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find the length of a word, using the variable c as a separator between words.
*/

size_t		ft_wordlen(const char *s, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i += 1;
	while (s[i] != c && s[i++])
		len += 1;
	return (len);
}
