/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 20:45:33 by rtorres-          #+#    #+#             */
/*   Updated: 2017/05/05 03:34:35 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

/*
** Required header files
*/

# include <ndbm.h>
# include <time.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

/*
** User defined header files
*/

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

/*
** Macros
*/

# define ERROR		(-1)
# define SIZE		(FT_BIT(16))
# define FLAGS(db)	(db->flg_c + db->flg_r + db->flg_u + db->flg_d)

/*
** ftdb structure
**
** @flg_c         : create flag
** @flg_r         : read flag
** @flg_u         : update flag
** @flg_d         : delete flag
** @filename      : database file
** @records       : records list
** @total_records : total number of records
** @new_database  : new database flag
*/

typedef struct	s_ftdb
{
	int		flg_c;
	int		flg_r;
	int		flg_u;
	int		flg_d;
	char	*filename;
	int		records[SIZE];
	int		total_records;
	int		new_database;
}				t_ftdb;

/*
** Prototypes
*/

void			db_read(DBM *file, t_ftdb *db);
void			db_create(DBM *file, t_ftdb *db);
void			db_update(DBM *file, t_ftdb *db);
void			db_delete(DBM *file, t_ftdb *db);
char			*db_serialize(void);
void			db_backup(t_ftdb *db);

#endif
