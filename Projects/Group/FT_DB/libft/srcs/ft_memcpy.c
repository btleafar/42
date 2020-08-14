/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:57:02 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:57:08 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i += 1;
	}
	return (dst);
}
