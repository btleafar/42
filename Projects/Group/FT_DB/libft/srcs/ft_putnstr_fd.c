/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:51:51 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:51:53 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string s to the file descriptor fd (len number of characters).
** If len is greater than the total len of the string s, it outputs the string
** completely.
*/

void	ft_putnstr_fd(char const *s, size_t len, int fd)
{
	if (s)
	{
		ft_strlen(s) < len ? len = ft_strlen(s) : len;
		write(fd, s, len);
	}
}
