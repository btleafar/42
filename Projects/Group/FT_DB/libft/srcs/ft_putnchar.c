/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:52:08 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:52:10 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the character c to the standard output, n number of times.
*/

void	ft_putnchar(char c, int n)
{
	while (n-- > 0)
		ft_putchar(c);
}
