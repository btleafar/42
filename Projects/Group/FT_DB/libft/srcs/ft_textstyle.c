/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textstyle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:17:41 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:38:08 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Style (attributes and colors) used for printed text.
** Uses the "\x1B" escape character.
** The first argument indicates the text attribute, the second arguments is used
** for the color of the text, and the third is for the background color.
** Attributes: RESET, BOLD, DIM, ITALICS, UNDERLINE, REVERSE, HIDDEN, STROKE
** Colors: BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
*/

void	ft_textstyle(int attr, int fg, int bg)
{
	ft_putstr("\x1B[");
	ft_putnbr(attr);
	ft_putnbr(fg + 30);
	ft_putnbr(bg + 40);
	ft_putchar('m');
}
