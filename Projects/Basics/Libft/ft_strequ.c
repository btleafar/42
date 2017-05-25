/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:02:00 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/22 14:02:02 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The tenary operators in the return is optional (? 1 : 0) as that is what
** the return operation does by default.
*/

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strcmp(s1, s2) == 0 ? 1 : 0);
}
