/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_attr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:55:03 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:55:05 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** Get flags, and store them in the atribute structure.
** If there's no flag, function returns a zero (0), else returns one (1).
**
** @HASH  : Used with o, x or X specifiers the value is preceeded with
**          0, 0x or 0X respectively for values different than zero.
**          By default, if no digits follow, no decimal point is written.
** @ZERO  : Left-pads the number with zeroes (0) instead of spaces
**          when padding is specified
** @MINUS : Left-justify within the given field width;
**          Right justification is the default
** @SPACE : If no sign is going to be written, a blank space is inserted
**          before the value.
** @PLUS  : Forces to preceed the result with a plus or minus sign (+ or -),
**          even for positive numbers. By default, only negative numbers are
**          preceded with a minus (-) sign.
*/

static int	get_flags(char flg, t_prntf *attr)
{
	flg == '#' ? attr->flags |= HASH : 0;
	flg == '0' ? attr->flags |= ZERO : 0;
	flg == '-' ? attr->flags |= MINUS : 0;
	flg == ' ' ? attr->flags |= SPACE : 0;
	flg == '+' ? attr->flags |= PLUS : 0;
	return (flg == '#' || flg == '0' || flg == '-' || flg == ' ' || flg == '+');
}

/*
** Controls the minimum number of characters that are output. If the number of
** characters in the output value is less than the specified width, blanks are
** added to the left or the right of the values—depending on whether the left
** alignment flag (-) is specified—until the minimum width is reached.
** @star (*) : Not specified in the format string, but as an additional integer
**             value argument preceding the argument that has to be formatted.
** @number   : Minimum number of characters to be printed. If the value to be
**             printed is shorter than this number, the result is padded with
**             blank spaces.
*/

static int	get_width(va_list arg, char *format, t_prntf *attr)
{
	int		width;
	char	*nbr;

	width = 0;
	if (format[width] == '*')
	{
		attr->width = va_arg(arg, int);
		if (attr->width < 0)
		{
			attr->width *= -1;
			attr->flags |= MINUS;
		}
		width = 1;
	}
	else
	{
		while (ft_isdigit(format[width]))
			width += 1;
		if (!width || !(nbr = ft_strsub(format, 0, width)))
			return (0);
		attr->width = ft_atoi(nbr);
		free(nbr);
	}
	return (width);
}

/*
** Specifies the number of string characters, the number of decimal places,
** or the number of significant digits to be output.
** For numbers, precision is the minimum number of digits to be written.
** If the value to be written is shorter than this number, the result is padded
** with leading zeros. The value is not truncated even if the result is longer.
** For strings, is the maximum number of characters to be printed.
** By default all characters are printed until a null character is encountered.
*/

static int	get_precision(va_list ap, char *format, t_prntf *attr)
{
	int		precision;
	char	*nbr;

	precision = 0;
	if (format[0] == '.')
	{
		precision = 1;
		if (format[precision] == '*')
		{
			attr->precision = va_arg(ap, int);
			precision += 1;
		}
		else
		{
			while (ft_isdigit(format[precision]))
				precision += 1;
			if (!(nbr = ft_strsub(format, 1, precision)))
				return (0);
			attr->precision = (precision != 1) ? ft_atoi(nbr) : 0;
			free(nbr);
		}
	}
	return (precision);
}

/*
** Modifies the length of the data type.
** The following chart shows the types used to interpret the corresponding
** specifier with and without the length specifier.
**
** length  | d i           | u o O x X b            | c      | s        | p
** -----------------------------------------------------------------------------
** (none)  | int           | unsigned int           | int    | char*    | void*
** hh      | signed char   | unsigned char          |        |          |
** h       | short int     | unsigned short int     |        |          |
** l       | long int      | unsigned long int      | wint_t | wchar_t* |
** ll      | long long int | unsigned long long int |        |          |
** j       | intmax_t      | uintmax_t              |        |          |
** z       | size_t        | size_t                 |        |          |
*/

static int	get_length(char *format, t_prntf *attr)
{
	int		length;

	length = 0;
	while (format[length] == 'h' || format[length] == 'l' \
			|| format[length] == 'j' || format[length] == 'z')
	{
		if (format[length] == 'h')
			format[length + 1] == 'h' \
				? (attr->flags |= HH) : (attr->flags |= H);
		if (format[length] == 'l')
			format[length + 1] == 'l' \
				? (attr->flags |= LL) : (attr->flags |= L);
		if (attr->flags == HH || attr->flags == LL)
			length += 1;
		if (format[length] == 'j')
			attr->flags |= J;
		if (format[length] == 'z')
			attr->flags |= Z;
		length += 1;
	}
	return (length);
}

/*
** Gets the flags, width, precision and length of the format.
** Returns a boolean value (one (1) or zero (0)), indicating if the format
** is valid.
*/

int			get_attributes(char **format, va_list arg, t_prntf *attr)
{
	char	*init;
	int		format_width;

	init = *format;
	while (get_flags(**format, attr))
		(*format)++;
	while ((format_width = get_width(arg, *format, attr)))
	{
		attr->flags |= WIDTH;
		(*format) += format_width;
	}
	while ((format_width = get_precision(arg, *format, attr)))
	{
		if (attr->precision >= 0)
			attr->flags |= PRECISION;
		(*format) += format_width;
	}
	while ((format_width = get_length(*format, attr)))
		(*format) += format_width;
	return (*format > init);
}
