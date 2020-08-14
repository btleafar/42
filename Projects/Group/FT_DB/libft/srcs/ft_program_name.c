/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:53:42 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:53:44 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Gets the name of the program (argv[0]).
*/

char	*ft_program_name(char const *argv0)
{
	char *name;

	name = (char *)argv0;
	while (*name && *name != '/')
		name += 1;
	if (!name)
		return ((char *)argv0);
	return (name + 1);
}
