/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_backup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:16:30 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:05:32 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*
** I'm writing to apologize for the behavior of this function.
** We all know that emotions can get heated when close calls are made in intense
** projects, but it does not excuse the language and behavior of this function.
** I, too, am personally shocked and offended by this, which are a direct
** contravention of the values of dignity we learn in our school.
** Please convey my personal apologies to you, the corrector, and for whom we
** have the utmost respect. Remember, system is ugly. Sorry. Forgive me. :(
*/

void		db_backup(t_ftdb *db)
{
	char	*dir;
	char	*filename;
	char	command[256];
	time_t	rawtime;

	dir = "backups/";
	if (mkdir(dir, 0775) == 0)
		ft_printf("Creating backup folder: %s\n", dir);
	filename = ft_strjoin(db->filename, ".db");
	snprintf(command, sizeof(command), "cat %s > %s%s.%s.db", \
			filename, dir, db->filename, ft_itoa(time(&rawtime)));
	system(command);
	free(filename);
}
