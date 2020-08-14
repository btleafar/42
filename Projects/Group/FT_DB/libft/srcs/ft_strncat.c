/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:55:02 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:40:30 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends not more than n characters from the string s2, to the end of the
** null-terminated string s1, then add a terminating '/0'. The string s1
** must have sufficient space to hold the result.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while ((i < n) && s2[i])
	{
		s1[i + j] = s2[i];
		i += 1;
	}
	s1[i + j] = '\0';
	return (s1);
}
