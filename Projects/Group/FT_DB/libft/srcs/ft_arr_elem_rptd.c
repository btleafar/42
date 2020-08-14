/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_elem_rptd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:42 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Will return the number of elements repeated in an int array.
*/

int		ft_arr_elem_rptd(int *arr, size_t size)
{
	int		i;
	int		j;
	int		cnt;

	i = -1;
	cnt = 0;
	if (size < 1)
		return (0);
	while ((unsigned int)++i < size)
	{
		j = i + 1;
		while ((unsigned int)j < size)
			if (arr[i] == arr[j++])
				cnt += 1;
	}
	return (cnt);
}
