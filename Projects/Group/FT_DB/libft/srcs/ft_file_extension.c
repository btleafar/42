/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 20:19:37 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:01:32 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Validates if the file has a specific file extension (given by ext string).
** Returns a one (1) if it does, returns zero (0) otherwise.
*/

int		ft_file_extension(char *file, char *ext)
{
	return (ft_strequ(ft_strrchr(file, '.'), ext));
}
