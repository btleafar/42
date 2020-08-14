/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:29:25 by rtorres-          #+#    #+#             */
/*   Updated: 2017/02/23 16:29:25 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates with malloc(), and returns a "fresh" string with the length of
** the total characters gotten up to the point that it finds a specific
** character. If the allocation fails the function returns NULL.
*/

char	*ft_strcut(const char *str, char c)
{
	int		len;
	char	*cut;

	len = 0;
	while (str[len] != c && str[len])
		if (str[len++] == c)
			break ;
	if (!(cut = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strncpy(cut, str, len);
	cut[len + 1] = '\0';
	return (cut);
}
