/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:36:05 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:37:45 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts a lower-case letter to the corresponding upper-case letter.
*/

int		ft_toupper(int c)
{
	if (c >= 'a' && 'z' >= c)
		return (c - 32);
	return (c);
}
