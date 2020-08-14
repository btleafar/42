/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:15:41 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:38:31 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates with malloc(), and returns a copy of the string given as argument
** without whitespaces at the beginning or at the end of the string.
** Will be considered as whitespaces the following characters ’ ’, ’\n’,
** and ’\t’. If s has no whites- paces at the beginning or at the end,
** the function returns a copy of s.
** If the allocation fails the function returns NULL.
*/

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ft_iswspace(s[i]))
		i += 1;
	j = ft_strlen(&s[i]) - 1;
	while (s[i] && ft_iswspace(s[j + i]))
		j -= 1;
	if (!(str = ft_strnew(j + 1)))
		return (NULL);
	ft_strncpy(str, (s + i), (j + 1));
	return (str);
}
