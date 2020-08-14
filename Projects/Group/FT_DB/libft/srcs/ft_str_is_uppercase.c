/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 02:12:28 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:47:34 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the string is alphabetical with uppercase letters only.
*/

int		ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (!ft_isupper(str[i++]))
			return (0);
	return (1);
}
