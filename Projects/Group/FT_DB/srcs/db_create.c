/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:16:30 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:05:39 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*
** Adds a record.
** Key value is defined by record number.
** Content is stored as a csv.
** If record already exists as the one that's going to be added, returns ERROR.
*/

static int	add_record(DBM *file, char **content, int record)
{
	datum	current_key;
	datum	current_data;

	current_key = dbm_firstkey(file);
	while (current_key.dptr != NULL)
	{
		if (ft_atoi(current_key.dptr) == record)
			return (ERROR);
		current_key = dbm_nextkey(file);
	}
	current_key.dptr = ft_itoa(record);
	current_key.dsize = ft_strlen(current_key.dptr) + 1;
	current_data.dptr = ft_separated_values(content, ',');
	current_data.dsize = ft_strlen(current_data.dptr) + 1;
	dbm_store(file, current_key, current_data, DBM_INSERT);
	return (0);
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
** Creates a new content using the record number passed as an arguments
** from the command line.
** If a record already matches one of the database, skip that one :)
*/

static int	create_content(DBM *file, t_ftdb *db)
{
	int		i;
	int		cols;
	char	**words;
	char	**values;
	datum	current_key;

	i = 0;
	current_key = dbm_firstkey(file);
	cols = ft_wordcount(dbm_fetch(file, current_key).dptr, ',');
	if (!(words = ft_strsplit(dbm_fetch(file, current_key).dptr, ',')))
		ft_puterror("Memory allocation failed! :(", 1);
	while (i < db->total_records)
	{
		ft_printf("Adding values for record [%d]...\n", db->records[i]);
		if ((values = get_values(cols, words)) == NULL)
			return (ERROR);
		if (add_record(file, values, db->records[i]) == ERROR)
			ft_printf("Hey! record [%d] already exist! :O\n", db->records[i]);
		free(values);
		i += 1;
	}
	return (0);
}

/*
** Creates a new database.
** Asks the user the number of columns, and the name of them.
*/

static int	new_database(DBM *file)
{
	int		i;
	int		cols;
	char	*line;
	char	*type;
	char	**values;

	ft_printf("Enter the number of columns : ");
	get_next_line(1, &line);
	if ((cols = ft_atoi(line)) < 1)
		return (ERROR);
	free(line);
	if (!(values = (char **)malloc(sizeof(char *) * cols + 1)))
		ft_puterror("Memory allocation failed! :(", 1);
	i = -1;
	while (++i < cols)
	{
		ft_printf("Name of column [%d] : ", (i + 1));
		get_next_line(1, &line);
		if (ft_strrchr(line, ',') != NULL || (type = db_serialize()) == NULL)
			return (ERROR);
		values[i] = ft_strjoin(type, ft_strdup(ft_strtrim(line)));
		free(line);
	}
	values[i] = NULL;
	return (add_record(file, values, 0));
}

/*
** Creates a new record to the database.
** If new_database flag is true, creates a new database.
*/

void		db_create(DBM *file, t_ftdb *db)
{
	if (db->new_database == 1)
		if (new_database(file) == ERROR)
		{
			unlink(ft_strjoin(db->filename, ".db"));
			ft_puterror("Error while creating a new database! :(", 5);
		}
	if (db->total_records > 0 && dbm_firstkey(file).dptr != NULL)
		if (create_content(file, db) == ERROR)
		{
			unlink(ft_strjoin(db->filename, ".db"));
			ft_puterror("Not a valid input!", 7);
		}
}
