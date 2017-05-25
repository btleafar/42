/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:51:57 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/23 08:52:01 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Added ((!s1) == (!s2)) in the return to add the condition for when !n is
** true or in other words a comparison between 0 and 0, which is true.
** It can be done by: if (!s1 || !s2) return (0); if (!n) return (1);
**
** The tenary operators in the return is optional (? 1 : 0) as that is what
** the return operation does by default.
*/

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return ((!s1) == (!s2));
	return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
}
