/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:58:11 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:58:13 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a “fresh” link.
** The variables content and content_size of the new link are initialized by
** copy of the parameters of the function.
** If the parameter content is nul, the variable content is initialized
** to NULL and the variable content_size is initialized to 0 even if the
** parameter content_size isn’t. The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
