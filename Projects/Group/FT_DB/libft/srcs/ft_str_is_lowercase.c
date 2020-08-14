/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 01:32:09 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:48:03 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the string is alphabetical with lowercase letters only.
*/

int		ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (!ft_islower(str[i++]))
			return (0);
	return (1);
}
