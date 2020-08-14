/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:04:06 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy the content of an int array to another one.
*/

int		*ft_arr_cpy(const int *arr, size_t size)
{
	int				*cpy;
	unsigned int	i;

	cpy = ft_arr_new(size);
	i = 0;
	while (i < size)
	{
		cpy[i] = arr[i];
		i += 1;
	}
	return (cpy);
}
