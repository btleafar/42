/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_serialize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 03:25:17 by anieto            #+#    #+#             */
/*   Updated: 2017/05/05 03:39:56 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*
** Add a prefix to the name of the column, matching a data type.
** It goes as follows:
** @ i: -> int
** @ s: -> string
** @ f: -> float
** If the user enters an invalid input, show a waning message.
*/

char	*db_serialize(void)
{
	char	*type;
	char	*data;
	char	*line;

	type = NULL;
	ft_printf("Enter data type [int (i), float (f), or string (s)] : ");
	get_next_line(1, &line);
	data = ft_strdup(ft_strtrim(line));
	free(line);
	ft_str_to_lowcase(data);
	if (ft_strequ(data, "i") || ft_strequ(data, "int"))
		type = "i:";
	else if (ft_strequ(data, "s") || ft_strequ(data, "string"))
		type = "s:";
	else if (ft_strequ(data, "f") || ft_strequ(data, "float"))
		type = "f:";
	free(data);
	if (type == NULL)
		ft_printf("Not a valid data type\n");
	return (type);
}
