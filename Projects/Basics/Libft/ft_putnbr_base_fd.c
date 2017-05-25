/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:22:12 by rtorres-          #+#    #+#             */
/*   Updated: 2016/11/24 15:22:13 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long n, int base, int fd)
{
	int		divisor;
	int		result;

	if (base < 2 || base > 16)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	divisor = 1;
	while (n / divisor >= base)
		divisor *= base;
	while (divisor > 0)
	{
		result = (n / divisor) % base;
		ft_putchar_fd(HEXNUMS[result], fd);
		divisor /= base;
	}
}
