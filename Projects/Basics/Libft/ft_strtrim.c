/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:22:13 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/23 15:22:15 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_simple_space = (*s == ' ' || *s == '\t' || *s == '\n')
*/

#include "libft.h"

static char	*ft_strltrim(char const *s)
{
	while (ft_simple_space(*s))
		s++;
	return (ft_strdup(s));
}

static char	*ft_strrtrim(char const *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len == 0)
		return (ft_strnew(0));
	len--;
	while (len && s[len] && ft_simple_space(s[len]))
		len--;
	return (ft_strsub(s, 0, (len + 1)));
}

char		*ft_strtrim(char const *s)
{
	char	*result;

	if (!s)
		return (NULL);
	result = ft_strdup(s);
	if (!result)
		return (NULL);
	result = ft_strltrim(result);
	if (!result)
		return (NULL);
	result = ft_strrtrim(result);
	if (!result)
		return (NULL);
	return (result);
}
