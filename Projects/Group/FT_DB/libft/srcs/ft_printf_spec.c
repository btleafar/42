/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:54:15 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:54:17 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** Gets every specifier position from the format.
*/

static int	specifier_position(char c, char *spec)
{
	int		pos;

	pos = 0;
	while (spec[pos])
	{
		if (c == spec[pos])
			return (pos);
		pos += 1;
	}
	return (PRINTF_FAILURE);
}

/*
** Gets which specifier is in the format, and encode it given its respective bit
** value (going from bit five (5), to bit eighteen (18) for the mandatory
** specifiers, and bit twenty-seven (27) for the bonus, the binary).
*/

static int	get_specifier(char c, t_prntf *attr, char *spec)
{
	int		*corres;
	int		specifier;

	corres = ft_memalloc(sizeof(int) * SPECI_SIZE);
	corres[LOWER_S] = LOW_S_BIT;
	corres[UPPER_S] = UPP_S_BIT;
	corres[LOWER_P] = LOW_P_BIT;
	corres[LOWER_D] = LOW_D_BIT;
	corres[UPPER_D] = UPP_D_BIT;
	corres[LOWER_I] = LOW_I_BIT;
	corres[LOWER_O] = LOW_O_BIT;
	corres[UPPER_O] = UPP_O_BIT;
	corres[LOWER_U] = LOW_U_BIT;
	corres[UPPER_U] = UPP_U_BIT;
	corres[LOWER_X] = LOW_X_BIT;
	corres[UPPER_X] = UPP_X_BIT;
	corres[LOWER_C] = LOW_C_BIT;
	corres[UPPER_C] = UPP_C_BIT;
	corres[LOWER_B] = LOW_B_BIT;
	if (((specifier = specifier_position(c, spec)) != PRINTF_FAILURE) && c)
		attr->flags |= corres[specifier];
	free(corres);
	return (specifier);
}

/*
** Parse the specifier, returning the specifier positing.
** If the attribute isn't valid, returns a printf error.
*/

int			parse_specifier(va_list arg, char **format, t_prntf *attr)
{
	int		specifier;
	int		is_valid;
	char	*conversion;

	attr->flags = 0;
	if (!(conversion = (char *)malloc(sizeof(char) * SPECI_SIZE)))
		return (0);
	conversion = ft_strncpy(conversion, SPECIFIERS, SPECI_SIZE);
	specifier = PRINTF_FAILURE;
	while (**format)
	{
		if ((specifier_position(**format, conversion) != PRINTF_FAILURE) \
				&& (specifier = get_specifier(**format, attr, conversion)))
			break ;
		if (!(is_valid = get_attributes(format, arg, attr)))
			break ;
	}
	free(conversion);
	return (specifier);
}
