/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:45:41 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/16 22:14:41 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memset - Fill a region of memory with the given value
** @b: Pointer to the start of the area.
** @c: The byte to fill the area with
** @len: The size of the area.
**
** Do not use memset() to access IO space, use memset_io() instead.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)b;
	while (len--)
		*temp++ = (unsigned char)c;
	return (b);
}
