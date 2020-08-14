/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:58:04 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:58:06 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees a matrix (2 dimensional dynamic array).
*/

void		ft_mat_del(int **matrix, int row)
{
	int		i;

	i = 0;
	while (i <= row)
	{
		free(matrix[i]);
		matrix[i++] = NULL;
	}
	free(matrix);
	matrix = NULL;
}
