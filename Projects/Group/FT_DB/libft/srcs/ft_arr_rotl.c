/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_rotl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:27 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Rotate the elements to the left of an array, by how many position defined
** in the tms variable. If the tms variable is greater than the number of
** elements, it's going to be trimed down to the next min value.
** For example, we have an array with three (3) elements, and we say that we
** want to rotate it 5 times. tms will be trimed to 2 times (5 - 3 = 2), and
** then we rotate it 2 times only.
*/

int		*ft_arr_rotl(int *arr, size_t size, unsigned int tms)
{
	int				last;
	unsigned int	i;

	if (!tms || !arr)
		return (arr);
	last = arr[0];
	i = 0;
	while (tms > size)
		tms -= size;
	while (i < (size - 1))
	{
		arr[i] = arr[i + 1];
		i += 1;
	}
	arr[size - 1] = last;
	tms -= 1;
	if (tms)
		ft_arr_rotl(arr, size, tms);
	return (arr);
}
