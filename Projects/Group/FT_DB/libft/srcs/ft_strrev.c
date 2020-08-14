/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 06:39:10 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:39:29 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function that reverses (in-place) a string.
*/

char		*ft_strrev(char *str)
{
	char	*p1;
	char	*p2;

	if (!str || !*str)
		return (str);
	p1 = str;
	p2 = str + ft_strlen(str) - 1;
	while (p2 > p1)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
		++p1;
		--p2;
	}
	return (str);
}
