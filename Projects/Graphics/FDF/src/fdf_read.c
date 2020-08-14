/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:25:52 by rtorres-          #+#    #+#             */
/*   Updated: 2017/02/23 05:25:53 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Gets the number values in each line from the fdf file.
** If there's an invalid character in the line, prints an error message.
** Sometimes my fdf calaquea, asi que I added "read error" in the error message,
** because my gnl is broken? or some shit like that... It happens very rarely.
*/

static int	count_values(char *line)
{
	int		len;

	len = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			len += 1;
			while (ft_isdigit(*line))
				line += 1;
		}
		else if (*line != ' ' && *line != '-')
			ft_puterror("Invalid characters or read error...lel ???（ ^_^)", 5);
		line += 1;
	}
	return (len);
}

/*
** Count and returns the number of lines (rows) that the file has.
** This value is used to allocate the correct memory size
** for the two dimensional array.
** If the total values from every line is not equal to the other lines,
** there is an error with the fdf file... lel.
*/

static int	count_lines(t_fdf *fdf, char *argv)
{
	int		fd;
	int		len;
	int		rows;
	int		cols;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterror("Error opening file! :(", 1);
	rows = 0;
	cols = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		if ((len = count_values(line)) > cols)
			cols = len;
		(cols == len) ? rows += 1 : ft_puterror("Not a valid file! >_<", 4);
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("Error closing file! WTF?! :)", 2);
	if (!(fdf->map.width = cols))
		ft_puterror("Not a valid file! >_<", 4);
	return (rows);
}

/*
** Gets and store the values from the file into a two dimensional array,
** by atoi-ing every little fucker (converting from ascii to ints).
*/

static void	get_values(t_fdf *fdf, int y, int z, char *line)
{
	int		i;
	char	**split;

	if ((split = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (split[i] && (y != fdf->map.width))
		{
			fdf->map.values[z][y] = ft_atoi(split[i++]);
			y += 1;
		}
		free(split);
	}
}

/*
** Read the fdf file, allocates in memory the correct size of the height
** and width of the map.
*/

void		fdf_read(char *argv, t_fdf *fdf)
{
	int		y;
	int		z;
	int		fd;
	char	*line;

	y = 0;
	z = 0;
	fdf->map.height = count_lines(fdf, argv);
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterror("Error opening file! :(", 1);
	if (!(fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height)))
		ft_puterror("Memory Allocation failed! :O", 3);
	while (get_next_line(fd, &line) == 1 && z != fdf->map.height)
	{
		if (!(fdf->map.values[z] = (int *)malloc(sizeof(int) * fdf->map.width)))
			ft_puterror("Memory Allocation failed! :O", 3);
		get_values(fdf, y, z, line);
		y = 0;
		z += 1;
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("Error closing file! WTF?! :)", 2);
}
