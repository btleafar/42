/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lowcase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 20:38:54 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:47:28 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Makes every letter in the string lowercase.
*/

char	*ft_str_to_lowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i++])
		if (ft_isupper(str[i - 1]))
			str[i - 1] += 32;
	return (str);
}
