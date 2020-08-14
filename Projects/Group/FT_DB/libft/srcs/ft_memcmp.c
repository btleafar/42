/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:57:14 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:57:16 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares byte string s1 against byte string s2. Both strings are assumed
** to be n bytes long.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while ((i < n) && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i += 1;
	if (i == n)
		return (0);
	else
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
