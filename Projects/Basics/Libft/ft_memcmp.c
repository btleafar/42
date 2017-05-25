/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:56:14 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/18 16:56:17 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_memcmp - Compare two areas of memory
** @s1:	One area of memory
** @s2:	Another area of memory
** @n:	The size of the area.
*/

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*area1;
	const unsigned char	*area2;
	int					result;

	result = 0;
	while (n > 0)
	{
		area1 = (const unsigned char *)s1;
		area2 = (const unsigned char *)s2;
		if ((result = *area1 - *area2) != 0)
			break ;
		s1++;
		s2++;
		n--;
	}
	return (result);
}
