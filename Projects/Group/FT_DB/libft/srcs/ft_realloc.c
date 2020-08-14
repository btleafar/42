/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 05:06:13 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:50:15 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Change the size of the allocation pointed to by ptr to size, and returns ptr.
** If there is not enough room to enlarge the memory allocation pointed to by
** ptr, this function creates a new allocation, copies as much of the old data
** pointed to by ptr as will fit to the new allocation, frees the old
** allocation, and returns a pointer to the allocated memory.
** If ptr is NULL, this function is identical to malloc() for size bytes.
** If size is zero and ptr is not NULL, a new, minimum sized object is
** allocated and the original object is freed.
*/

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr)
	{
		if (size)
		{
			if (!(new_ptr = ft_memalloc(size)))
				return (NULL);
			ft_bzero(new_ptr, size);
			ft_memcpy(new_ptr, ptr, size);
		}
		else
		{
			if (!(new_ptr = (unsigned char *)malloc(sizeof(ptr))))
				return (NULL);
		}
		free(ptr);
		return (new_ptr);
	}
	return ((unsigned char *)malloc(sizeof(ptr) * size));
}
