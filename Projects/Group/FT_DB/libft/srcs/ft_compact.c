/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:27:38 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:01:50 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compact the elements of an array.
** Remove elements from the middle of an array by setting up a start point
** and end point in the array.
*/

int		ft_compact(char **tab, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		while (*(tab + i))
			i += 1;
		j = i;
		length -= 1;
		while (j < length)
		{
			*(tab + j) = *(tab + j + 1);
			j += 1;
		}
	}
	return (length);
}
