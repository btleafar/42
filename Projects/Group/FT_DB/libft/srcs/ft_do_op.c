/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:01:46 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Will do a math operation (depending on the value of the variable op) to the
** first number (nbr1) and the second number (nbr2), in that order. If the
** op value isn't a math operator, or if there is a division by zero (0), it
** will return a one.
*/

int		ft_do_op(int nbr1, int nbr2, char op)
{
	if (op == '+')
		return (nbr1 + nbr2);
	if (op == '-')
		return (nbr1 - nbr2);
	if (op == '*')
		return (nbr1 * nbr2);
	if (op == '/')
		if (nbr2 != 0)
			return (nbr1 / nbr2);
	if (op == '%')
		if (nbr2 != 0)
			return (nbr1 % nbr2);
	return (0);
}
