/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 02:24:17 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:47:43 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the string is can be printed.
*/

int		ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (!ft_isprint(str[i++]))
			return (0);
	return (1);
}
