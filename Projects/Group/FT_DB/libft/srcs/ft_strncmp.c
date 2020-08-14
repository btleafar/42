/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:08:08 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:40:22 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compares not more than n characters of the
** null-terminated strings s1 and s2.  characters that appear after a `\0'
** character are not compared.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (!n)
		return (0);
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while ((*us1 && (*us1 == *us2)) && --n)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		us1 += 1;
		us2 += 1;
	}
	return (*us1 - *us2);
}
