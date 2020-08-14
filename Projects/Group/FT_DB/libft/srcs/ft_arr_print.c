/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:03:30 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints the content of an int array. With *encl, one can select how the
** numbers will be enclosed. If the number of characters isn't equal to two (2),
** then curly braces {} will be used as default.
*/

void	ft_arr_print(int *arr, size_t size, char *encl)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(encl) != 2)
		encl = "{}";
	while (i < (size - 1))
	{
		ft_putchar(encl[0]);
		ft_putnbr(arr[i++]);
		ft_putchar(encl[1]);
		ft_putstr(", ");
	}
	ft_putchar(encl[0]);
	ft_putnbr(arr[i]);
	ft_putchar(encl[1]);
	ft_putstr("\n");
}
