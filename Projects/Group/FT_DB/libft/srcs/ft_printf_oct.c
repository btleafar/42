/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:54:30 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:54:32 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** Converts the number to base eight (8) (octal), using the get_nbr_unsigned
** function.
*/

static char	*convert_octal(uintmax_t nbr, int *nbdig)
{
	return (get_nbr_unsigned(nbr, nbdig, 8));
}

/*
** Returns the length of the octal number to be printed, depending in the
** length gotten with the flags.
*/

int			print_octal(va_list ap, t_prntf *attr)
{
	int		len;

	if (attr->flags & J)
		len = format_unsigned(va_arg(ap, uintmax_t), attr, &convert_octal);
	else if (attr->flags & Z)
		len = format_unsigned(va_arg(ap, size_t), attr, &convert_octal);
	else if (attr->flags & LL)
		len = format_unsigned(va_arg(ap, unsigned long long), attr, \
								&convert_octal);
	else if (attr->flags & L || attr->flags & UPP_O_BIT)
		len = format_unsigned(va_arg(ap, unsigned long), attr, &convert_octal);
	else if (attr->flags & H)
		len = format_unsigned((unsigned short)va_arg(ap, unsigned int), attr,
			&convert_octal);
	else if (attr->flags & HH)
		len = format_unsigned((unsigned char)va_arg(ap, unsigned int), attr,
			&convert_octal);
	else
		len = format_unsigned(va_arg(ap, unsigned int), attr, &convert_octal);
	return (len);
}
