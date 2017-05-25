/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_print_solution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumez-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 03:47:11 by iumez-er          #+#    #+#             */
/*   Updated: 2016/12/20 03:47:31 by iumez-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit_write_str(char *s, int m, char *str)
{
	int i;
	int j;

	i = 0;
	j = (int)ft_strlen(s);
	if (m == 'A')
	{
		while (i < g_info.sqsize)
			str[i++] = '.';
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '1')
			str[g_info.sqsize - j + i] = m;
		i++;
	}
	str[g_info.sqsize] = '\0';
}

void	ft_fillit_print_solution(int **tetrix)
{
	char	**str;
	int		i;
	int		l;

	str = (char **)malloc(sizeof(char *) * (g_info.sqsize + 1));
	if (!str)
		return ;
	l = 0;
	while (l < g_info.sqsize)
	{
		str[l] = (char *)malloc(sizeof(char) * (g_info.sqsize + 1));
		if (!str)
			return ;
		i = 0;
		while (i < g_info.ntetras)
		{
			ft_fillit_write_str(ft_itoa_base(tetrix[i][l] >> COL, 2), \
				tetrix[i][19], str[l]);
			i++;
		}
		ft_putstr(str[l]);
		ft_putchar('\n');
		free(str[l]);
		l++;
	}
}

/*
**void	ft_fillit_putstr(char const *s, int m)
**{
**	int i;
**	int j;
**
**	i = 0;
**	j = (int)ft_strlen(s);
**	while (j < g_info.sqsize)
**	{
**		ft_putchar('.');
**		j++;
**	}
**	while (s[i])
**	{
**		if (s[i] == '1')
**			ft_putchar(m);
**		else if (s[i] == '0')
**			ft_putchar('.');
**		i++;
**	}
**}
*/
/*
**void	ft_fillit_print_solution2(int **tetrix)
**{
**	int i;
**	int l;
**	int tmp;
**
**	i = 0;
**	while (i <= g_info.ntetrs)
**	{
**		if (i == g_info.ntetras)
**			LETTER = '*';
**		l = 0;
**		while (l < g_info.sqsize)
**		{
**			tmp = tetrix[i][l] >> COL;
**			ft_fillit_putstr(ft_itoa_base(tmp, 2), LETTER, g_info.sqsize);
**			l++;
**			ft_putchar('|');
**		}
**		ft_putchar('\n');
**		i++;
**	}
**}
*/
