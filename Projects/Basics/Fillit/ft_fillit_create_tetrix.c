/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumez-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:01:02 by iumez-er          #+#    #+#             */
/*   Updated: 2016/12/12 23:08:14 by iumez-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** creates a map composed of 2d integer array. Each row is one piece
** 0 - ntetraminos - 1. the ntetraminos row serves as the bit map for all the
** pieces
** the first 12 cols are the empty sq puzzle we are trying to solve;
** the last 10 cols are data of the pieces
** the data for each piece is converted from a string of 1s and 0s to integers.
*/

void	populate_tetraminos(int **tetrix, char *tetras[][8])
{
	int i;
	int j;

	i = 0;
	while (i <= g_info.ntetras)
	{
		tetrix[i] = (int *)malloc(sizeof(int) * 23);
		if (!tetrix[i])
			return ;
		j = 0;
		while (j < 13)
			tetrix[i][j++] = 0;
		tetrix[i][13] = ft_bi_2_int(convert_str(tetras[i][1], g_info.sqsize));
		tetrix[i][14] = ft_bi_2_int(convert_str(tetras[i][2], g_info.sqsize));
		tetrix[i][15] = ft_bi_2_int(convert_str(tetras[i][3], g_info.sqsize));
		tetrix[i][16] = ft_bi_2_int(convert_str(tetras[i][4], g_info.sqsize));
		ROW = 0;
		COL = 0;
		LETTER = 'A' + i;
		WIDTH = ft_atoi(tetras[i][6]);
		HEIGHT = ft_atoi(tetras[i][7]);
		i++;
	}
}

/*
**clears the map once we failed to find a solution using the previous sqsize
*/

void	ft_fillit_clear_tetraminos(int **tetrix)
{
	int i;

	i = 0;
	while (i < g_info.ntetras)
		free(tetrix[i++]);
}

/*
** starts w/ the smallest possible size (2*2) then,
** while the area is less than the number of spaces that need to be filled, it
** attemps to solve at that sqsize but if it fails increases the sqsize and
** reinitializes the matrix of pieces & map (tetrix)
*/

int		ft_find_smallest_square(char *tetras[][8])
{
	int i;
	int **tetrix;

	tetrix = (int **)malloc(sizeof(int *) * g_info.ntetras + 1);
	if (!tetrix)
		return (0);
	g_info.sqsize = 2;
	while ((g_info.sqsize * g_info.sqsize) < g_info.ntetras * 4)
		g_info.sqsize++;
	populate_tetraminos(tetrix, tetras);
	i = 0;
	while (!ft_fillit_solve_sq(tetrix, i))
	{
		ft_fillit_clear_tetraminos(tetrix);
		g_info.sqsize++;
		populate_tetraminos(tetrix, tetras);
	}
	ft_fillit_print_solution(tetrix);
	return (g_info.sqsize);
}
