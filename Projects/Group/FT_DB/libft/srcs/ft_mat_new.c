/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:57:56 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:57:58 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Responsible for allocating a matrix (2 dimensional dynamic array).
*/

int			**ft_mat_new(int row, int col)
{
	int		i;
	int		**matrix;

	i = 0;
	if (!(matrix = (int **)ft_calloc(sizeof(int *) * row, 0)))
		return (0);
	while (i < row)
	{
		if (!(matrix[i] = (int *)ft_calloc(sizeof(int) * col, 0)))
			return (0);
		i++;
	}
	return (matrix);
}
