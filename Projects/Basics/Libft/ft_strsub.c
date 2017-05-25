/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:20:58 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/23 09:21:00 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (!s)
		return (NULL);
	mem = ft_strnew(len);
	if (!mem)
		return (NULL);
	ft_strncpy(mem, s + start, len);
	mem[len] = 0;
	return (mem);
}
