/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_do_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:49 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Will aplay a math operation to all the elements of an int array.
** For example, if op == '*', all the elements will be multiplied by whatever
** number was assigned to the val variable.
** arr_op[0] = (2 * 2); -> arr_op[0] = 4;
** arr_op[1] = (6 * 2); -> arr_op[1] = 12;
** arr_op[2] = (8 * 2); -> arr_op[2] = 16;
*/

int		*ft_arr_do_op(const int *arr, size_t size, char op, int val)
{
	int				*arr_op;
	unsigned int	i;

	if (!(ft_ismathop(op)))
		return ((int *)arr);
	arr_op = ft_arr_new(size);
	i = 0;
	while (i < size)
	{
		arr_op[i] = ft_do_op(arr[i], val, op);
		i += 1;
	}
	return (arr_op);
}
