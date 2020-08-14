/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:58:58 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:59:00 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element new at the beginnning of the list.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*elem;

	elem = new;
	elem->next = *alst;
	*alst = elem;
}
