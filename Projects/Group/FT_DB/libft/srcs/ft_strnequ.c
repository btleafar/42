/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:18:33 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:40:00 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographical comparison between s1 and s2 up to n char- acters or until a
** ’\0’ is reached. If the 2 strings are identical, the function returns 1,
** or 0 otherwise.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
		if (!n || !ft_strncmp(s1, s2, n))
			return (1);
	return (0);
}
