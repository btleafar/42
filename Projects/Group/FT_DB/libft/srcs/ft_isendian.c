/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isendian.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:10:50 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:00:29 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the character is a math operator.
*/

int		ft_is_little_endian(void)
{
	int little;

	little = 1;
	if (*(char *)&little == 1)
		return (1);
	else
		return (0);
}
