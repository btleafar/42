/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:38:13 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:37:53 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts an upper-case letter to the corresponding lower-case letter.
*/

int		ft_tolower(int c)
{
	if (c >= 'A' && 'Z' >= c)
		return (c + 32);
	return (c);
}
