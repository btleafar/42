/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:51:59 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:52:02 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string s to the standard output up to len number of characters.
** If len is greater than the total len of the string s, it outputs the string
** completely.
*/

void	ft_putnstr(char const *s, size_t len)
{
	if (s)
	{
		ft_strlen(s) < len ? len = ft_strlen(s) : len;
		write(1, s, len);
	}
}
