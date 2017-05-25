/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:49:01 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/11 23:07:53 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strcpy - Copy a %NUL terminated string
** @dst: Where to copy the string to
** @src: Where to copy the string from
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
