/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:16:05 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/26 16:16:07 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strcapitalize takes one or several strings and, for each argument,
** capitalizes the first character of each word (If it's a letter, obviously),
** puts the rest in lowercase, and displays the result on the standard output,
** followed by a \n.
**
** A "word" is defined as a part of a string delimited either by spaces/tabs, or
** by the start/end of the string. If a word only has one letter, it must be
** capitalized.
**
** If there are no arguments, the progam must display \n.
*/

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;
	int upper;

	i = 0;
	upper = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || \
				(str[i] >= 'a' && str[i] <= 'z') || \
				(str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (upper == 1 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (upper == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			upper = 0;
		}
		else
			upper = 1;
		write(1, &str[i], 1);
		i++;
	}
	return (str);
}
