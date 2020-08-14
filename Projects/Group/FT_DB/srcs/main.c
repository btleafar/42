/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:16:30 by rtorres-          #+#    #+#             */
/*   Updated: 2017/04/24 21:16:31 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*
** Prints ft_db usage message.
*/

static void	usage_message(char *progname)
{
	ft_putstr("Usage: ");
	ft_putstr(progname);
	ft_putstr(" [ -c | -r | -u | -d ] [ database_file ] [ record(s) ]\n");
	ft_printf("Try: '%s -h' for more information.\n", progname);
}

/*
** Prints ft_db help message.
*/

static void	help_message(char *progname)
{
	ft_printf("Usage %s [ OPTION ]... [ FILE ] [ RECORD(S) ]... \n", progname);
	ft_putendl("Creates a database file.\n");
	ft_putendl("Mandatory arguments to long and short options are mandatory");
	ft_putendl("-c, --create \t creates a new database or a new record");
	ft_putendl("-r, --read \t prints a database or a specific record");
	ft_putendl("-u, --update \t updates a database or a specific record");
	ft_putendl("-d, --delete \t deletes a database or a specific record\n");
	ft_putendl("By default, whenever the database must be modified, a backup " \
	"will be created in a backup directory.");
	exit(0);
}

/*
** Parse the arguments from the command line.
** @ -h or --help   : help_message
** @ -c or --create : create record(s)
** @ -r or --read   : read record(s)
** @ -u or --update : update record(s)
** @ -d or --delete : delete record(s)
*/

static int	parse_arguments(char *argv[], t_ftdb *db)
{
	int		i;
	int		j;

	if (ft_strequ(argv[1], "-h") || ft_strequ(argv[1], "--help"))
		help_message(argv[0]);
	else if (ft_strequ(argv[1], "-c") || ft_strequ(argv[1], "--create"))
		db->flg_c = 1;
	else if (ft_strequ(argv[1], "-r") || ft_strequ(argv[1], "--read"))
		db->flg_r = 1;
	else if (ft_strequ(argv[1], "-u") || ft_strequ(argv[1], "--update"))
		db->flg_u = 1;
	else if (ft_strequ(argv[1], "-d") || ft_strequ(argv[1], "--delete"))
		db->flg_d = 1;
	if ((db->filename = argv[2]) == NULL)
		return (ERROR);
	i = 2;
	j = -1;
	while (argv[++i] != NULL)
	{
		if (ft_str_is_numeric(argv[i]) == 0)
			return (ERROR);
		db->records[++j] = ft_atoi(argv[i]);
	}
	db->total_records = j + 1;
	return (0);
}

/*
** Open the database file (if it doesn't exist, create a new one).
** Depending on the CRUD flags, do the respective operations.
*/

static void	operate_db(t_ftdb *db)
{
	int		i;
	DBM		*file;

	i = 0;
	if (access(db->filename, F_OK) == -1 && db->flg_c != 1)
		ft_puterror("Are you sure the file exists? Lol.", 3);
	if (ft_file_extension(db->filename, ".db") == 0)
		ft_puterror("Are you sure it's a valid .db file???", 4);
	db->new_database = (access(db->filename, F_OK) == -1) ? 1 : 0;
	db->filename = ft_remove_extension(db->filename);
	if ((file = dbm_open(db->filename, O_RDWR | O_CREAT, 0664)) == (DBM *)0)
		ft_puterror("Error opening database file! :/", 2);
	if (db->flg_c == 1)
		db_create(file, db);
	else if (db->flg_r == 1)
		db_read(file, db);
	else if (db->flg_u == 1)
		db_update(file, db);
	else if (db->flg_d == 1)
		db_delete(file, db);
	dbm_close(file);
}

/*
** Main function.
** Creates the database structure, parse the arguments from the command line,
** and get things rolling.
** If the number of arguments are invalid, prints ft_db usage_message.
**
** Useful sources:
** https://www.mitchr.me/SS/exampleCode/DB/rdNDBM.c.html
** https://www.mitchr.me/SS/exampleCode/DB/mkNDBM.c.html
** http://infolab.stanford.edu/~ullman/dbsi/win98/ndbm.html
** https://jwhsmith.net/2014/03/lightweight-databases-in-c-gdbm/
*/

int			main(int argc, char *argv[])
{
	t_ftdb	*db;

	if (argc > 1)
	{
		if ((db = (t_ftdb *)malloc(sizeof(t_ftdb))) == NULL)
			ft_puterror("Memory allocation failed! :(", 1);
		if (parse_arguments(argv, db) == ERROR || FLAGS(db) != 1)
			ft_puterror("Missing or not valid argument(s) >:(", 6);
		operate_db(db);
	}
	else
		usage_message(argv[0]);
	return (0);
}
