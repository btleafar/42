/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:27:38 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:38 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the value of the array’s biggest element.
*/

int		ft_arr_max(int *arr, int length)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (++i < length)
		if (max > arr[i])
			max = arr[i];
	return (max);
}
