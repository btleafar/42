/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:53:59 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:54:01 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** Prints number of spaces.
*/

int		print_spaces(int width, int len, int attr)
{
	while ((width - len) > 0)
	{
		ft_putchar(((attr & ZERO) && !(attr & MINUS)) ? '0' : ' ');
		len += 1;
	}
	return (len);
}

/*
** Prints string of wide characters.
*/

int		print_wide_string(va_list ap, t_prntf *attr)
{
	int		len;
	wchar_t	*str;
	wchar_t	*cpy;

	if (!(str = va_arg(ap, wchar_t *)))
		str = ft_wcsdup(L"(null)");
	if (attr->flags & PRECISION)
	{
		cpy = ft_wcsnew(attr->precision);
		if (str)
			cpy = ft_wcsncpy(cpy, str, attr->precision);
		str = cpy;
	}
	len = ft_wcslen(str);
	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, len, attr->flags);
	ft_putwstr(str);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, len, attr->flags);
	return (len);
}

/*
** Prints wide characters.
*/

int		print_wide_character(va_list ap, t_prntf *attr)
{
	int		len;
	wchar_t	c;

	c = va_arg(ap, wint_t);
	len = ft_wclen(c);
	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, len, attr->flags);
	ft_putwchar(c);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, len, attr->flags);
	return (len);
}

/*
** Prints string of characters.
*/

int		print_string(va_list ap, t_prntf *attr)
{
	int		len;
	char	*str;
	char	*cpy;

	if (attr->flags & L)
		return (print_wide_string(ap, attr));
	if (!(str = va_arg(ap, char *)))
		str = ft_strdup("(null)");
	if (attr->flags & PRECISION)
	{
		if (!(cpy = (char *)malloc(sizeof(char) * attr->precision)))
			return (0);
		cpy = ft_strncpy(cpy, str, attr->precision);
		str = cpy;
	}
	len = ft_strlen(str);
	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, len, attr->flags);
	ft_putstr(str);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, len, attr->flags);
	return (len);
}

/*
** Prints characters.
*/

int		print_character(va_list ap, t_prntf *attr)
{
	int		len;
	char	c;

	if (attr->flags & L)
		return (print_wide_character(ap, attr));
	c = va_arg(ap, int);
	len = sizeof(char);
	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, len, attr->flags);
	ft_putchar(c);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, len, attr->flags);
	return (len);
}
