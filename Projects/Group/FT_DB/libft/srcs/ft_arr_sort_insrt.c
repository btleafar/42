/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_sort_insrt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:16 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sort the elements of an int array by insertion.
*/

void	ft_arr_sort_insrt(int *arr, size_t size)
{
	int		i;
	int		j;
	int		current;

	i = 0;
	j = 0;
	while ((unsigned int)i < size)
	{
		current = arr[i];
		j = i - 1;
		while (j >= 0 && (arr[j] > current))
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = current;
		i += 1;
	}
}
