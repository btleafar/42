/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:58:18 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:58:20 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list, resulting from the successive applications of f. If the
** allocation fails, the function returns NULL.
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*iter;

	if (!lst || !(iter = ft_lstnew(NULL, 0)))
		return (NULL);
	iter = f(lst);
	head = iter;
	while (lst->next)
	{
		lst = lst->next;
		iter->next = f(lst);
		iter = iter->next;
	}
	return (head);
}
