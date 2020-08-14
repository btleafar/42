/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:56:23 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:56:25 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes len bytes of value c (converted to an unsigned char) to the string b.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ub;

	ub = (unsigned char *)b;
	while (len--)
		*ub++ = (unsigned char)c;
	return (b);
}
