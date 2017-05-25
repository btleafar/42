/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:27:54 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/13 02:07:43 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strcat - Append one %NUL-terminated string to another
** @s1: The string to be appended to
** @s2: The string to append to it
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *temp;

	temp = s1;
	while (*s1)
		s1++;
	while ((*s1++ = *s2++) != '\0')
		;
	return (temp);
}
