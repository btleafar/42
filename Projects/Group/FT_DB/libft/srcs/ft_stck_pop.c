/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stck_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:15:16 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:49:15 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The main reason for keeping the top of the stack static is to make it easy
** to maintainthe new top of the stack and also to return the top data value
** that is popped or removed from the stack.
*/

double	ft_stck_pop(t_stack *top)
{
	double	value;
	t_stack	*tmp;

	if (top)
	{
		tmp = top->next;
		if (tmp != NULL)
		{
			value = tmp->value;
			top->next = tmp->next;
			free(tmp);
			return (value);
		}
	}
	return (top->value);
}
