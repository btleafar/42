/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:23:56 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/16 22:24:03 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**The bzero() function writes n zeroed bytes to the string s.
**If n is zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
