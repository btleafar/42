/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_upcase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 20:38:54 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:47:20 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Makes every letter in the string uppercase.
*/

char	*ft_str_to_upcase(char *str)
{
	int		i;

	i = 0;
	while (str[i++])
		if (ft_islower(str[i - 1]))
			str[i - 1] -= 32;
	return (str);
}
