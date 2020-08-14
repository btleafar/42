/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:57:38 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:57:40 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates with malloc() and returns a “fresh” memory area. The memory
** allocated is initialized to 0.
** If the allocation fails, the function returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size)
	{
		if (!(ptr = (unsigned char *)malloc(size)))
			return (NULL);
		while (size)
			ptr[--size] = 0;
	}
	return ((void *)ptr);
}
