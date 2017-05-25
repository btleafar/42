/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:02:07 by rtorres-          #+#    #+#             */
/*   Updated: 2016/12/15 11:03:31 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define TETRIMINO_WIDTH	(4 + 1)
# define TETRIMINO_HEIGHT	4
# define MAX_TETRIMINOS		26
# define MAX_TETRIMINO_SIZE	(TETRIMINO_WIDTH * TETRIMINO_HEIGHT)
# define BUFFER_SIZE		(MAX_TETRIMINOS * (MAX_TETRIMINO_SIZE + 1))

/*
** BUFFER_SIZE = 546
*/

# define ROW (tetrix[i][17])
# define COL (tetrix[i][18])
# define LETTER (tetrix[i][19])
# define WIDTH (tetrix[i][20])
# define HEIGHT (tetrix[i][21])
# define TMP1 (tetrix[i][l] >> tetrix[i][18])

/*
** 0 - unique rep 1-4 rows rep to feed solver
** 5-valid start postions 6- width 7-height
*/

static char		*g_tetraminos[20][8] =
{
	{"1111", "1111", "", "", "", "0", "3", "0"},
	{"1000100010001", "1", "1", "1", "1", "0123", "0", "3"},
	{"110010001", "11", "1", "1", "", "012", "1", "2"},
	{"1110001", "111", "001", "", "", "01", "2", "1"},
	{"0100010011", "01", "01", "11", "", "123", "1", "2"},
	{"1000111", "1", "111", "", "", "01", "2", "1"},
	{"1100010001", "11", "01", "01", "", "012", "1", "2"},
	{"11101", "111", "1", "", "", "01", "2", "1"},
	{"1000100011", "1", "1", "11", "", "012", "1", "2"},
	{"0010111", "001", "111", "", "", "23", "2", "1"},
	{"110011", "11", "11", "", "", "012", "1", "1"},
	{"010011001", "01", "11", "1", "", "123", "1", "2"},
	{"1100011", "11", "011", "", "", "01", "2", "1"},
	{"1000110001", "1", "11", "01", "", "012", "1", "2"},
	{"011011", "011", "11", "", "", "12", "2", "1"},
	{"111001", "111", "01", "", "", "01", "2", "1"},
	{"100011001", "1", "11", "1", "", "012", "1", "2"},
	{"0100110001", "01", "11", "01", "", "123", "1", "2"},
	{"0100111", "01", "111", "", "", "12", "2", "1"},
	{"0", "", "", "", "", "0123", "0", "0"}
};

typedef struct	s_tet
{
	int			count;
	int			count2;
	int			sqsize;
	int			ntetras;
}				t_tet;

t_tet			g_info;

/*
** Libft functions...may need to change itoa base slightly.
*/

void			ft_putstr(char *str);
size_t			ft_strlen(const char *s);
char			*ft_itoa_base(int value, int base);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
char			*ft_strstr(const char *big, const char *little);

/*
** Checking functions
*/

int				valid_elems(char *input);
int				check_new_lines(char *input);
int				count_the_lines(char *input);
int				check_dot_pounds(char *input);
int				check_orderoffig(char *input);
char			*ft_read(char *file);
int				check_in_pattern(char *input);
void			check_matrix(char *input);

/*
** Initializing Functions
*/

void			populate_tetraminos(int **tetrix, char *tetras[26][8]);
void			ft_fillit_clear_tetraminos(int **tetrix);
int				ft_find_smallest_square(char *tetras[26][8]);

/*
** Solving funtions
*/

void			ft_fillit_put_map(int **tetrix, int i);
void			ft_fillit_clear_tetramino_rows(int **tetrix, int i);
void			ft_fillit_put_tetramino(int **tetrix, int i);
int				ft_fillit_valid_place(int **tetrix, int i);
int				ft_fillit_solve_sq(int **tetrix, int i);

/*
** Helper funtions
*/

char			*convert_str(char *str, int sqsize);
int				ft_bi_2_int(char *str);
int				ft_iterative_power(int base, int power);

/*
** Printing solution (two ways, first is for assignment)
** second is conceptual model
*/

void			ft_fillit_print_solution(int **tetrix);
void			ft_fillit_write_str(char *s, int m, char *str);

/*
** void		ft_fillit_print_solution2
** (int **tetrix, int sqsize, int ntetraminos);
** void		ft_fillit_putstr(char const *s, int m, int sqsize);
*/

#endif
