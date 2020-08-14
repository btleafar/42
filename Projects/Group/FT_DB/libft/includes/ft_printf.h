/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 00:44:14 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:04:41 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Header to allow ft_printf to accept an indefinite number of arguments.
*/

# include <stdarg.h>

/*
** Macro used when there's an error with the printf.
*/

# define PRINTF_FAILURE (-1)

/*
** Printf's attribute structure.
*/

typedef struct		s_prntf
{
	int		flags;
	int		precision;
	int		width;
}					t_prntf;

/*
** @ s or s : String of characters
** @ p      : Pointer address
** @ D or i : Signed decimal integer
** @ o or O : Signed octal
** @ u or U : Unsigned decimal integer
** @ x      : Unsigned hexadecimal integer
** @ X      : Unsigned hexadecimal integer (capital letters)
** @ c or C : Character
** @ b      : Binary
*/

# define SPECIFIERS	"sSpdDioOuUxXcCb"
# define SPECI_SIZE	(ft_strlen(SPECIFIERS))

/*
** Encoding used for the SPECIFIERS macro string.
*/

# define LOWER_S	(0)
# define UPPER_S	(1)
# define LOWER_P	(2)
# define LOWER_D	(3)
# define UPPER_D	(4)
# define LOWER_I	(5)
# define LOWER_O	(6)
# define UPPER_O	(7)
# define LOWER_U	(8)
# define UPPER_U	(9)
# define LOWER_X	(10)
# define UPPER_X	(11)
# define LOWER_C	(12)
# define UPPER_C	(13)
# define LOWER_B	(14)

/*
** Encoding for every attribute of the printf, representing one bit for
** every single thingy.
*/

# define HASH		(FT_BIT(0))
# define ZERO		(FT_BIT(1))
# define MINUS		(FT_BIT(2))
# define PLUS		(FT_BIT(3))
# define SPACE		(FT_BIT(4))
# define LOW_S_BIT	(FT_BIT(5))
# define UPP_S_BIT	(FT_BIT(6))
# define LOW_P_BIT	(FT_BIT(7))
# define LOW_D_BIT	(FT_BIT(8))
# define UPP_D_BIT	(FT_BIT(9))
# define LOW_I_BIT	(FT_BIT(10))
# define LOW_O_BIT	(FT_BIT(11))
# define UPP_O_BIT	(FT_BIT(12))
# define LOW_U_BIT	(FT_BIT(13))
# define UPP_U_BIT	(FT_BIT(14))
# define LOW_X_BIT	(FT_BIT(15))
# define UPP_X_BIT	(FT_BIT(16))
# define LOW_C_BIT	(FT_BIT(17))
# define UPP_C_BIT	(FT_BIT(18))
# define HH			(FT_BIT(19))
# define H			(FT_BIT(20))
# define LL			(FT_BIT(21))
# define L			(FT_BIT(22))
# define J			(FT_BIT(23))
# define Z			(FT_BIT(24))
# define WIDTH		(FT_BIT(25))
# define PRECISION	(FT_BIT(26))
# define LOW_B_BIT	(FT_BIT(27))

/*
** ft_printf prototype
*/

int					ft_printf(const char *format, ...);

/*
** Prototypes from the auxiliary functions.
*/

int					parse_specifier(va_list arg, char **format, t_prntf *attr);
int					print_spaces(int width, int len, int attr);
int					get_attributes(char **format, va_list arg, t_prntf *attr);
int					get_nbr_zeroes(t_prntf *attr, int *len, int sign);
int					get_nbr_spaces(int attr, int minw, int *len);
char				*get_nbr_unsigned(uintmax_t n, int *nbdig, int base);
int					format_signed(intmax_t n, t_prntf *attr);
int					format_unsigned(uintmax_t n, t_prntf *attr, \
						char *(*convert)(uintmax_t, int *));

/*
** Prototypes from the print functions.
*/

int					print_string(va_list ap, t_prntf *attr);
int					print_wide_string(va_list ap, t_prntf *attr);
int					print_hexadecimal(va_list ap, t_prntf *attr);
int					print_decimal(va_list ap, t_prntf *attr);
int					print_octal(va_list ap, t_prntf *attr);
int					print_character(va_list ap, t_prntf *attr);
int					print_wide_character(va_list ap, t_prntf *attr);
int					print_binary(va_list ap, t_prntf *attr);

#endif
