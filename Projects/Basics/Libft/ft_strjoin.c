/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:35:32 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/23 14:35:34 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;

	if (!s1 || !s2)
		return (NULL);
	mem = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!mem)
		return (NULL);
	ft_strncpy(mem, s1, ft_strlen(s1));
	ft_strncat(mem, s2, ft_strlen(s2));
	return (mem);
}
