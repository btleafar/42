/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_rotr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:23 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Rotate the elements to the right of an array, by how many position defined
** in the tms variable. If the tms variable is greater than the number of
** elements, it's going to be trimed down to the next min value.
** For example, we have an array with three (3) elements, and we say that we
** want to rotate it 5 times. tms will be trimed to 2 times (5 - 3 = 2), and
** then we rotate it 2 times only.
*/

int		*ft_arr_rotr(int *arr, size_t size, unsigned int tms)
{
	int				first;
	unsigned int	i;

	if (!tms || !arr)
		return (arr);
	first = arr[size - 1];
	i = size;
	while (tms > size)
		tms -= size;
	while (i)
	{
		arr[i] = arr[i - 1];
		i -= 1;
	}
	arr[i] = first;
	tms -= 1;
	if (tms)
		ft_arr_rotr(arr, size, tms);
	return (arr);
}
