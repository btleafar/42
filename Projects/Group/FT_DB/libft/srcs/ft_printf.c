/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:55:15 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:55:16 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** If no specifier is found, prints the character, plus the specific
** justification given the minus flag: (left or right).
*/

static int	print_no_specifier(char c, t_prntf *attr)
{
	int		len;

	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, sizeof(char), attr->flags);
	ft_putchar(c);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, sizeof(char), attr->flags);
	return (len);
}

/*
** Prints the specific specifier given from the format.
*/

static int	print_specifier(char format, va_list arg, t_prntf *attr, int i)
{
	int		print;

	if (i == LOWER_S)
		print = print_string(arg, attr);
	else if (i == UPPER_S)
		print = print_wide_string(arg, attr);
	else if ((i == LOWER_D || i == UPPER_D || i == LOWER_I) \
				|| (i == LOWER_U || i == UPPER_U))
		print = print_decimal(arg, attr);
	else if (i == LOWER_O || i == UPPER_O)
		print = print_octal(arg, attr);
	else if (i == LOWER_P || i == LOWER_X || i == UPPER_X)
		print = print_hexadecimal(arg, attr);
	else if (i == LOWER_C)
		print = print_character(arg, attr);
	else if (i == UPPER_C)
		print = print_wide_character(arg, attr);
	else if (i == LOWER_B)
		print = print_binary(arg, attr);
	else
		print = print_no_specifier(format, attr);
	return (print);
}

/*
** If successful, the total number of characters written is returned.
** On failure, a negative number is returned (defined by PRINTF_FAILURE macro).
*/

static int	print_stdout(const char *format[], va_list arg)
{
	int		specifier;
	t_prntf	attribute;

	attribute.flags = 0;
	attribute.width = 0;
	attribute.precision = 0;
	specifier = parse_specifier(arg, (char **)format, &attribute);
	if (!**format)
		return (PRINTF_FAILURE);
	return (print_specifier((char)**format, arg, &attribute, specifier));
}

/*
** Writes the string pointed by format to the standard output (stdout),
** replacing any format specifier in the same way as printf does, but using the
** elements in the variable argument list identified by arg instead of
** additional function arguments.
*/

int			ft_printf(const char *format, ...)
{
	int		len;
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			if ((len = print_stdout(&format, arg)) == PRINTF_FAILURE)
				break ;
			count += len;
		}
		else
		{
			ft_putchar(*format);
			count += 1;
		}
		format += 1;
	}
	va_end(arg);
	return (count);
}
