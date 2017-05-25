/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:06:01 by rtorres-          #+#    #+#             */
/*   Updated: 2016/12/15 11:03:42 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Reading and closing the input file
*/

char	*ft_read(char *file)
{
	int		file_descriptor;
	char	*buffer;
	int		result;

	file_descriptor = open(file, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	buffer = (char *)malloc(BUFFER_SIZE);
	result = read(file_descriptor, buffer, BUFFER_SIZE);
	if (result == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	close(file_descriptor);
	return (buffer);
}

/*
** Begining of the program.
*/

int		ft_fillit_determine_shape(char *rep)
{
	int k;

	k = 0;
	g_info.count2 = 0;
	while (k < 19)
	{
		if (ft_strstr(rep, g_tetraminos[k][0]))
			return (k);
		k++;
	}
	return (19);
}

void	ft_fillit_extract_tetramino(char *buffer, char *tetras[][8], char *rep)
{
	while (*buffer)
	{
		g_info.count = 0;
		while (g_info.count < 16)
		{
			if (*buffer == '#')
				rep[g_info.count++] = '1';
			if (*buffer == '.')
				rep[g_info.count++] = '0';
			buffer++;
		}
		rep[g_info.count] = '\0';
		g_info.count = ft_fillit_determine_shape(rep);
		while (g_info.count2 < 8)
		{
			tetras[g_info.ntetras][g_info.count2] = \
			g_tetraminos[g_info.count][g_info.count2];
			g_info.count2++;
		}
		if (*buffer == '\n')
		{
			g_info.ntetras++;
			buffer++;
		}
	}
}

void	ft_add_blank_last_row(char *tetras[][8])
{
	g_info.count = 0;
	while (g_info.count < 8)
	{
		tetras[g_info.ntetras][g_info.count] = g_tetraminos[19][g_info.count];
		g_info.count++;
	}
}

int		main(int argc, char **argv)
{
	char		*buffer;
	char		*tetras[27][8];
	char		*rep;

	rep = (char *)malloc(sizeof(char) * 17);
	if (!rep)
		return (0);
	if (argc == 2)
	{
		buffer = ft_read(argv[1]);
		check_matrix(buffer);
		ft_fillit_extract_tetramino(buffer, tetras, rep);
		ft_add_blank_last_row(tetras);
		free(buffer);
	}
	else
	{
		ft_putstr("usage: ./fillit file_name\n");
		exit(-1);
	}
	ft_find_smallest_square(tetras);
	return (0);
}
