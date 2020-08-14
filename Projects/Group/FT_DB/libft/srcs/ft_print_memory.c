/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:55:23 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:55:25 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Displays the memory area onscreen, splitting it into three columns:
**   - The hexadecimal address of the first line’s first character.
**   - The content in hexadecimal.
**   - The content in printable characters.
** If a character is non-printable, it’ll be replaced by a dot.
*/

static void	print_hex(int i, unsigned int size, unsigned char *p)
{
	char			*str;
	unsigned int	j;

	j = 0;
	str = "0123456789abcdef";
	while (j < 16 && i + j < size)
	{
		ft_putchar((char)str[(*(p + i + j) / 16) % 16]);
		ft_putchar((char)str[*(p + i + j) % 16]);
		if (j % 2)
			ft_putchar(' ');
		j += 1;
	}
	while (j < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (j % 2)
			ft_putchar(' ');
		j += 1;
	}
}

void		ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned char	*p;

	str = "0123456789abcdef";
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex(i, size, p);
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (*(p + i + j) >= 32 && *(p + i + j) <= 126)
				ft_putchar((char)*(p + i + j));
			else
				ft_putchar('.');
			j += 1;
		}
		ft_putchar('\n');
		i += 16;
	}
}
