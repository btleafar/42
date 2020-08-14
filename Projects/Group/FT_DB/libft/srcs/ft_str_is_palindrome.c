/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_palindrome.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:37:58 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:47:49 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the string is palindrome.
*/

int		ft_str_is_palindrome(char *str)
{
	int		i;
	int		j;

	if (!str)
		return (0);
	i = -1;
	j = ft_strlen(str);
	while (i < j)
		if (!(str[++i] == str[--j]))
			return (0);
	return (1);
}
