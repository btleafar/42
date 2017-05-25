/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:21:43 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/11 23:09:30 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		len;

	len = ft_strlen(s1) + 1;
	str = (char*)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
