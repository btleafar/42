/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 01:44:14 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/16 01:44:17 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.hpp"

// Global variables for the windows and screen size.
Vector screen_min, screen_max;
WINDOW *main_win, *info_win, *stats_win;

void
initMonitor(void)
{
  main_win = initscr();
  cbreak();
  noecho();
  curs_set(0);
  clear();
  screen_max = Vector(COLS, LINES);
  if (screen_max.x < 42 || screen_max.y < 21) {
    endwin();
    std::cerr << "Window terminal is too small... :(" << std::endl;
    exit(1);
  }
  int info_panel_h = 4;
  info_win = newwin(screen_max.y - info_panel_h - 2, screen_max.x - 2,
                    screen_min.y + 1, screen_min.x + 1);
  stats_win = newwin(info_panel_h - 1, screen_max.x - 10,
                    (screen_max.y - info_panel_h), 2);
  main_win = newwin(screen_max.y, screen_max.x, 0, 0);
  keypad(main_win, true);
  nodelay(main_win, true);
  refresh();
  return ;
}
