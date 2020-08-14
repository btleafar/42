/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 03:25:17 by anieto            #+#    #+#             */
/*   Updated: 2020/08/13 22:05:44 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*
** Delete a record by matching the record number.
*/

static void	delete_record(DBM *db, int record)
{
	datum	current_key;

	current_key = dbm_firstkey(db);
	while (current_key.dptr != NULL)
	{
		if (ft_atoi(current_key.dptr) == record)
		{
			if (dbm_delete(db, current_key) < 0)
				ft_puterror("Something went wrong!\n", 8);
			break ;
		}
		current_key = dbm_nextkey(db);
	}
	if (current_key.dptr != NULL)
		ft_printf("Record [%d] was deleted!\n", record);
	else
		ft_printf("Hmmm... record [%d] doesn't exist. 🤔\n", record);
}

/*
** Deletes a record from the database.
** If the user tries to delete record[0] (master), give a warning! :O
** If no record is selected, prints a message to the user.
*/

void		db_delete(DBM *file, t_ftdb *db)
{
	int		i;

	i = 0;
	if (db->total_records > 0 && dbm_firstkey(file).dptr != NULL)
	{
		db_backup(db);
		while (i < db->total_records)
		{
			if (db->records[i] != 0)
				delete_record(file, db->records[i]);
			else
				ft_printf("Noob! You can't delete record [0]\n");
			i += 1;
		}
	}
	else
		ft_printf("Please specify one or more records.\n");
}
