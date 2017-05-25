/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:31:52 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/26 16:31:54 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_search_and_replace recive un string con texto, un char con el caracter
** a identificar dentro del string y otro parametro char con el valor a
** remplazar.
** Exemples:
** $>./search_and_replace "Papache est un sabre" "a" "o"
** Popoche est un sobre
*/

#include "libft.h"

void	ft_search_and_replace(char *str, char c, char new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i] = new;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}
