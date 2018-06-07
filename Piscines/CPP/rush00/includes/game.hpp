/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:24:16 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 23:22:25 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <unistd.h>
# include <ncurses.h>
# include <iostream>
# include <string>
# include "Vec.hpp"
# include "SpaceObject.hpp"
# include "ObjectField.hpp"
# include "Player.hpp"
# include "Ivan.hpp"
# include "IvanField.hpp"

int  init(void);
void run(void);
void close(void);
void new_game(void);
void reset(void);
void info(WINDOW *info_win, int lives, int score);
void pause_menu(void);

#endif
