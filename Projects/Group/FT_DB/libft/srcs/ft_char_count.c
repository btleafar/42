/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:16:30 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:02:48 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the total number of characters in a set of words.
** For example, a two word set, like: [Hello][World], returns 10.
*/

size_t		ft_char_count(char **values)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (values[i] != NULL)
		j += ft_strlen(values[i++]);
	i -= 1;
	return (i + j);
}
