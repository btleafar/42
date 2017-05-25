/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumez-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 23:38:24 by iumez-er          #+#    #+#             */
/*   Updated: 2016/11/21 15:07:23 by iumez-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *big_ptr;
	char *lil_ptr;

	if (*little == '\0')
		return ((char *)big);
	while (*little != '\0' && *big != '\0')
	{
		if (*little == *big)
		{
			big_ptr = (char *)big;
			lil_ptr = (char *)little;
			while (*lil_ptr == *big_ptr)
			{
				lil_ptr++;
				big_ptr++;
				if (*lil_ptr == '\0')
					return ((char *)big);
			}
		}
		big++;
	}
	return (0);
}
