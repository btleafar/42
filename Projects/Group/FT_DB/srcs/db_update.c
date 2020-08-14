/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:16:30 by rtorres-          #+#    #+#             */
/*   Updated: 2017/04/24 21:16:31 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*
** Updates a record.
** Content is stored as a csv.
** Key value is defined by record number.
*/

static void	update_record(DBM *file, char **content, int record)
{
	datum	current_key;
	datum	current_data;

	current_key.dptr = ft_itoa(record);
	current_key.dsize = ft_strlen(current_key.dptr) + 1;
	current_data.dptr = ft_separated_values(content, ',');
	current_data.dsize = ft_strlen(current_data.dptr) + 1;
	dbm_store(file, current_key, current_data, DBM_REPLACE);
}

/*
** Get the content value from the user, from the stdin.
** Saves the values as an array of strings.
*/

static char	**get_values(int cols, char **words)
{
	int		i;
	char	*line;
	char	**values;
	char	type;

	i = 0;
	if (!(values = (char **)malloc(sizeof(char *) * cols + 1)))
		ft_puterror("Memory allocation failed! :(", 1);
	while (i < cols)
	{
		type = words[i][0];
		ft_printf("%s: ", &words[i][2]);
		get_next_line(1, &line);
		values[i] = ft_strdup(ft_strtrim(line));
		if (ft_strrchr(line, ',') != NULL)
			return (NULL);
		free(line);
		i += 1;
	}
	values[i] = NULL;
	return (values);
}

/*
** Updates the content using the record number passed as an arguments
** from the command line.
** If the record doesn't match with any of the database, prints a warning.
*/

static void	update_content(DBM *file, int record)
{
	char	**content;
	datum	header;
	datum	current_key;
	datum	current_data;

	current_key = dbm_firstkey(file);
	header = dbm_fetch(file, current_key);
	while (current_key.dptr != NULL)
	{
		if (ft_atoi(current_key.dptr) == record)
		{
			ft_printf("Updating values for record [%d]...\n", record);
			current_data = dbm_fetch(file, current_key);
			content = get_values(ft_wordcount(header.dptr, ','), \
									ft_strsplit(header.dptr, ','));
			update_record(file, content, record);
			break ;
		}
		current_key = dbm_nextkey(file);
	}
	if (current_key.dptr != NULL)
		ft_printf("Record [%d] was updated!\n", record);
	else
		ft_printf("Hmmm... record [%d] doesn't exist. 🤔\n", record);
}

/*
** Updates a record from the database.
** If the user tries to update record[0] (master), give a warning! :O
** If no record is selected, prints a message to the user.
*/

void		db_update(DBM *file, t_ftdb *db)
{
	int		i;

	i = 0;
	if (db->total_records > 0 && dbm_firstkey(file).dptr != NULL)
	{
		db_backup(db);
		while (i < db->total_records)
		{
			if (db->records[i] != 0)
				update_content(file, db->records[i]);
			else
				ft_printf("Noob! You can't update record [0]\n");
			i += 1;
		}
	}
	else
		ft_printf("Please specify one or more records.\n");
}
