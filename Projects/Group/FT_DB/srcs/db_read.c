/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 03:25:17 by anieto            #+#    #+#             */
/*   Updated: 2017/05/05 03:39:56 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*
** Prints a record with a cool format. :)
*/

static void	print_record(datum current_key, datum current_data)
{
	int		i;
	char	**content;

	i = 0;
	content = ft_strsplit(current_data.dptr, ',');
	if (ft_atoi(current_key.dptr) == 0)
		ft_printf("| %*s ", -6, "Record");
	else
		ft_printf("| %*s ", 6, current_key.dptr);
	while (content[i] != NULL)
	{
		ft_printf("| %*s ", -12, content[i]);
		i += 1;
	}
	ft_putstr("|\n");
}

/*
** Reads an entire database, and prints record by record.
*/

static void	read_entire_db(DBM *file)
{
	datum	current_key;
	datum	current_data;

	current_key = dbm_firstkey(file);
	while (current_key.dptr != NULL)
	{
		current_data = dbm_fetch(file, current_key);
		print_record(current_key, current_data);
		current_key = dbm_nextkey(file);
	}
}

/*
** Find one or more records, and prints just those records.
*/

static void	read_records(DBM *file, int record)
{
	datum	current_key;
	datum	current_data;

	current_key = dbm_firstkey(file);
	while (current_key.dptr != NULL)
	{
		if (ft_atoi(current_key.dptr) == record)
		{
			current_data = dbm_fetch(file, current_key);
			print_record(current_key, current_data);
			return ;
		}
		current_key = dbm_nextkey(file);
	}
	ft_printf("Hmmm... record [%d] doesn't exist. 🤔\n", record);
}

/*
** Reads an entire database or just some record.
*/

void		db_read(DBM *file, t_ftdb *db)
{
	int		i;

	i = 0;
	if (db->total_records > 0)
		while (i < db->total_records)
			read_records(file, db->records[i++]);
	else
		read_entire_db(file);
}
