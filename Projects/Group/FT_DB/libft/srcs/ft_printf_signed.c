/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:54:23 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:54:25 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** Gets the number of digits of nbr. If nbr is zero, returns a one (1).
** If it's positive, returns how many digits the number has. If it's negative,
** returns the number of digits, plus an extra one for the negative sign (-).
*/

static int	nbr_digits(intmax_t nbr)
{
	int		len;

	if (!nbr)
		return (1);
	len = nbr < 0 ? 1 : 0;
	while (nbr)
	{
		nbr /= 10;
		len += 1;
	}
	return (len);
}

/*
** Prints the sign given of the number. If it's negative, it will always print
** the negative sign (-), else, and only if there is a flag with space or plus,
** the space or the plus sign (+) will be printed.
*/

static void	put_sign(intmax_t nbr, int attr)
{
	char	sign;

	sign = 0;
	if (nbr < 0)
		sign = '-';
	else if (nbr >= 0)
	{
		if (attr & PLUS)
			sign = '+';
		else if (attr & SPACE)
			sign = ' ';
	}
	if (sign)
		ft_putchar(sign);
}

/*
** Format a signed number, getting the number of digits, the number of zeroes
** and spaces, and the precision given from the format value.
** This is the second ugliest function I've ever written in my entire life. :(
** God bless you trying to understand this shit.
*/

int			format_signed(intmax_t nbr, t_prntf *attr)
{
	int		len;
	int		sign;
	int		nbr_zeros;
	int		nbr_spaces;

	len = 0;
	sign = (nbr >= 0 && (attr->flags & PLUS || attr->flags & SPACE)) ? 1 : 0;
	if (!(attr->flags & PRECISION) || attr->precision || nbr)
		len = nbr_digits(nbr);
	len += sign;
	nbr_zeros = get_nbr_zeroes(attr, &len, (nbr < 0 || sign));
	nbr_spaces = get_nbr_spaces(attr->flags, attr->width, &len);
	!(attr->flags & MINUS) ? ft_putnchar(' ', nbr_spaces) : 0;
	put_sign(nbr, attr->flags);
	ft_putnchar('0', nbr_zeros);
	if (!(attr->flags & PRECISION && !attr->precision && !nbr))
		ft_putunbr((nbr < 0) ? (-nbr) : (nbr));
	(attr->flags & MINUS) ? ft_putnchar(' ', nbr_spaces) : 0;
	return (len);
}
