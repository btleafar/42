/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:31:58 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/11 23:19:08 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncat - Append a length-limited, C-string to another
** @s1: The string to be appended to
** @s2: The string to append to it
** @n: The maximum numbers of bytes to copy
**
** Note that in contrast to strncpy(), strncat() ensures the result is
** terminated.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*temp;

	temp = s1;
	if (n)
	{
		while (*s1)
			s1++;
		while ((*s1++ = *s2++) != '\0')
		{
			if (--n == 0)
			{
				*s1 = '\0';
				break ;
			}
		}
	}
	return (temp);
}
