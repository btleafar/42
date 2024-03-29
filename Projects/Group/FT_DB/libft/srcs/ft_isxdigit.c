/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:59:31 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:59:32 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the character is a hexadecimal digit.
*/

int		ft_isxdigit(int c)
{
	return ((c >= '0' && '9' >= c) || (c >= 'a' && 'f' >= c) \
			|| (c >= 'A' && 'F' >= c));
}
