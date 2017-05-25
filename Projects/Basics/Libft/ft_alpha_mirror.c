/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_mirror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:07:48 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/26 16:07:50 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_alpha_mirror takes a string and displays the letters in the
** string after replacing each alphabetical character by the opposite
** alphabetical character.
*/

#include "libft.h"

void	ft_alpha_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = 'z' - str[i] + 'a';
			write(1, &str[i], 1);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = 'Z' - str[i] + 'A';
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
