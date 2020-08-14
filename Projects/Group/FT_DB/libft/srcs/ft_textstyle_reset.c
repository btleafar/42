/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textstyle_reset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:22:51 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:38:01 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Reset the attributes and colors of the printed text.
*/

void	ft_textstyle_reset(void)
{
	ft_putstr("\x1B[03040m");
}
