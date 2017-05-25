/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_solve_sq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumez-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:23:07 by iumez-er          #+#    #+#             */
/*   Updated: 2016/12/13 18:23:09 by iumez-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//int count;
/*
**Used for testing purpose, this was global
** int count;
** This was after base case in solve_sq function
**	count++;
**	if (count == 5000)
**	{
**		count = 1;
**		ft_fillit_print_solution2(tetrix, g_info.sqsize, g_info.ntetras);
**		ft_putstr("\n");
**	}
**			k = calc_empty_spaces(tetrix, i);
**			if (count == 1)
**				printf("number of emptyspaces is:%d, i is %d\n", \
** calc_empty_spaces(tetrix, i), i);
** This was to speed up algorightm for 12, 16 piece puzzles,didn't finish it
**int	calc_empty_spaces(int **tetrix, int i)
**{
**	int emptyspaces;
**	int tmp;
**
**	if (i)
**		ft_fillit_put_map(tetrix, i - 1);
**	g_info.count = 0;
**	emptyspaces = 0;
**	while (g_info.count < g_info.sqsize)
**	{
**		tmp = tetrix[g_info.ntetras][g_info.count];
**		if (!tmp)
**			emptyspaces += g_info.sqsize;
**		else
**		{
**			while (tmp)
**			{
**				if ((tmp % 2) == 0)
**					emptyspaces++;
**				tmp = tmp / 2;
**			}
**		}
**		g_info.count++;
**	}
**	return (emptyspaces);
**}
*/

void	ft_fillit_put_map(int **tetrix, int i)
{
	int k;
	int j;
	int temp1;
	int temp2;

	j = i;
	while (j >= 0)
	{
		k = 0;
		while (k < 12)
		{
			temp1 = tetrix[j][k] >> tetrix[j][18];
			temp2 = tetrix[g_info.ntetras][k];
			tetrix[g_info.ntetras][k] = temp1 | temp2;
			k++;
		}
		j--;
	}
}

/*
** as it states, clears the data for all ROW s of a piece
*/

void	ft_fillit_clear_tetramino_rows(int **tetrix, int i)
{
	int j;

	j = 0;
	while (j < 13)
		tetrix[i][j++] = 0;
}

/*
** called once you moved to a different tetramino, it clears all
** the row /data for that pieces and places it according to what the
** the start row  and col is.
*/

void	ft_fillit_put_tetramino(int **tetrix, int i)
{
	int k;
	int j;

	j = 0;
	while (j < 13)
		tetrix[i][j++] = 0;
	j = ROW;
	k = HEIGHT;
	while (k >= 0)
	{
		tetrix[i][j + k] = tetrix[i][13 + k];
		tetrix[g_info.ntetras][j + k] = 0;
		k--;
	}
}

/*
** Determines if the placement is valid by comparing the shifted value with
** the solution/map ROW (uses & bit operator to compare)
** TRUE means overlap, FALSE is valid placement, l is the ROW
*/

int		ft_fillit_valid_place(int **tetrix, int i)
{
	int l;
	int temp1;
	int temp2;

	l = 0;
	if (i)
		ft_fillit_put_map(tetrix, i - 1);
	while (l < g_info.sqsize)
	{
		temp1 = TMP1;
		temp2 = tetrix[g_info.ntetras][l];
		if (temp1 & temp2)
			return (0);
		l++;
	}
	return (1);
}

/*
** solves the sq by placing each piece after calling validity function
** which checks if the spot is valid - binary & against combination
** previously correct rows, stored in last element of tetrix[ntetras]
** if true (valid place) it recursively moves to the next piece
** if false it shifts the piece by one (col) until end of row ,
** then shifts the row.
** Once this is exhausted (at the last possible row ) the row is cleared
** algorithm backtracks to the previous piece.
** Once the map is empty, back track for i = 0,
** the program exits, increases sq size, repopulates and tries to solve again
*/

int		ft_fillit_solve_sq(int **tetrix, int i)
{
	if (i == g_info.ntetras)
		return (1);
	// count++;
	// if (count == 5000)
	// {
	// 	count = 1;
	// 	ft_fillit_print_solution(tetrix);
	// 	ft_putstr("\n");
	// }
	ROW = 0;
	while (ROW < g_info.sqsize - HEIGHT)
	{
		COL = 0;
		ft_fillit_put_tetramino(tetrix, i);
		while (COL >= 0 && COL < g_info.sqsize - WIDTH)
		{
			ft_fillit_put_tetramino(tetrix, i);
			if (ft_fillit_valid_place(tetrix, i))
			{
				ft_fillit_put_map(tetrix, i);
				if (ft_fillit_solve_sq(tetrix, i + 1))
					return (1);
			}
			COL += 1;
		}
		ROW += 1;
	}
	ft_fillit_clear_tetramino_rows(tetrix, i);
	return (0);
}
