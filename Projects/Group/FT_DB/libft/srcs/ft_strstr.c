/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:32:21 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:39:07 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the null-terminated string little
** in the null-terminated string big.
*/

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *)&big[i]);
	while (big[i])
	{
		while ((big[i + j] == little[j]) && little[j])
			j += 1;
		if (!little[j])
			return ((char *)&big[i]);
		j = 0;
		i += 1;
	}
	return (NULL);
}
