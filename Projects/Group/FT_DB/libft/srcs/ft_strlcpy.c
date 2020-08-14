/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:27:38 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:41:05 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes the destination's size as a parameter and will not write more than
** that many bytes, to prevent buffer overflow (assuming size is correct).
** Writes a single NULL byte to the destination (if size is not zero).
** The resulting string is guaranteed to be NULL-terminated even if truncated.
** Returns the length of the entire source string.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	ft_strncpy(dst, src, size);
	return (ft_strlen(src));
}
