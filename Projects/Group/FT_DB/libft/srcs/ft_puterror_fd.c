/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:52:41 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:52:44 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string msg to the file descriptor fd, followed by an exit of the
** program with a custom return value (defined by ret).
*/

void	ft_puterror_fd(char *msg, int ret, int fd)
{
	ft_putendl_fd(msg, fd);
	exit(ret);
}
