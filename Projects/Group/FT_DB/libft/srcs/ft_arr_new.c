/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:34 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new array with a specific set of numbers (by the argument size).
*/

int		*ft_arr_new(size_t size)
{
	int		*arr;

	if (!(arr = (int *)malloc(sizeof(int) * size)))
		return (0);
	while (size)
		arr[size--] = 0;
	return (arr);
}
