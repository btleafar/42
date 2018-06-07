/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:25:35 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 22:40:38 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

WINDOW *main_win;
WINDOW *game_win;
WINDOW *info_win;

Vec screenmin;
Vec screenmax;
Vec gamemin;
Vec gamemax;

Player player;

ObjectField *stars = new ObjectField();
ObjectField *asteroids = new ObjectField();

int init(void) {
  main_win = initscr();
  cbreak();
  noecho();
  curs_set(0);
  clear();
  if (!has_colors()) {
    endwin();
    std::cerr << "ERROR: Terminal does not support color." << std::endl;
    exit(1);
  }
  start_color();
  screenmax = Vec(COLS, LINES);
  if (screenmax.x < 42 || screenmax.y < 21) {
    endwin();
    std::cerr << "Window terminal is too small... :(" << std::endl;
    exit(2);
  }
  int info_panel_h = 4;
  game_win = newwin(screenmax.y - info_panel_h - 2, screenmax.x - 2,
                    screenmin.y + 1, screenmin.x + 1);
  info_win = newwin(info_panel_h - 1, screenmax.x - 10,
                    (screenmax.y - info_panel_h), 2);
  main_win = newwin(screenmax.y, screenmax.x, 0, 0);
  gamemax = Vec(screenmax.x - 2, screenmax.y - info_panel_h - 4);
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  keypad(main_win, true);
  keypad(game_win, true);
  nodelay(main_win, true);
  nodelay(game_win, true);
  nodelay(info_win, true);
  refresh();
  return 0;
}

void run(void) {
  bool exit_requested = false;
  bool gameover = false;
  int tick = 0;
  Vec max;
  int lives = 3;
  int score = 0;
  int in_char;

  stars->setBounds(gamemin, gamemax);
  asteroids->setBounds(gamemin, gamemax);
  player.setBounds(gamemin, gamemax);
  wattron(main_win, A_BOLD);
  box(main_win, 0, 0);
  wattroff(main_win, A_BOLD);
  wmove(main_win, gamemax.y + 3, 1);
  whline(main_win, '-', screenmax.x - 2);
  wrefresh(main_win);
  wrefresh(game_win);
  while (1) {
    werase(game_win);
    info(info_win, lives, score);

    Vec tmp;
    Vec tmp2;
    Vec ppos;
    Vec psize;
    ObjectField *pf;
    int todel;

    todel = 0;
    if (tick % 7 == 0) stars->update();
    for (int j = 0; j < stars->getCount(); j++) {
      tmp = stars->getObj(j)->getPos();
      wattron(game_win, A_DIM);
      mvwaddch(game_win, tmp.y, tmp.x, '.');
      wattroff(game_win, A_DIM);
    }

    pf = player.getPF();
    pf->update();
    for (int j = 0; j < pf->getCount(); j++) {
      tmp = pf->getObj(j)->getPos();
      wattron(game_win, COLOR_PAIR(2));
      mvwaddch(game_win, tmp.y, tmp.x, '|');
      wattroff(game_win, COLOR_PAIR(2));
    }

    if (tick > 100 && tick % 20 == 0) asteroids->update();
    for (int j = 0; j < asteroids->getCount(); j++) {
      tmp = asteroids->getObj(j)->getPos();
      wattron(game_win, COLOR_PAIR(4));
      mvwaddch(game_win, tmp.y, tmp.x, '*');
      wattroff(game_win, COLOR_PAIR(4));
    }

    ppos = player.getPos();
    psize = player.getSize();
    for (int j = 0; j < asteroids->getCount(); j++) {
      tmp = asteroids->getObj(j)->getPos();
      if ((tmp.x >= ppos.x - 1 && tmp.x <= ppos.x + psize.x - 2) &&
          tmp.y == ppos.y) {
        asteroids->del(j);
        j--;
        lives--;
        if (!lives) gameover = true;
      }
    }
    for (int i = 0; i < pf->getCount(); i++) {
      tmp2 = pf->getObj(i)->getPos();
      for (int j = 0; j < asteroids->getCount(); j++) {
        tmp = asteroids->getObj(j)->getPos();
        if (tmp2 == tmp) {
          asteroids->del(j);
          pf->del(i);
          j--;
          i--;
          score += 100;
          break;
        }
      }
    }

    in_char = wgetch(main_win);
    in_char = std::tolower(in_char);
    switch (in_char) {
      case 'q':
      case 27:  // ESC character ASCII code
        exit_requested = true;
        break;
      case KEY_UP:
      case 'w':
      case 'i':
        if (ppos.y > gamemin.y) player.move(Vec(0, -1));
        break;
      case KEY_DOWN:
      case 's':
      case 'k':
        if (ppos.y < gamemax.y + 1) player.move(Vec(0, 1));
        break;
      case KEY_LEFT:
      case 'a':
      case 'j':
        if (ppos.x > gamemin.x + 1) player.move(Vec(-1, 0));
        break;
      case KEY_RIGHT:
      case 'd':
      case 'l':
        if (ppos.x < gamemax.x - 2) player.move(Vec(1, 0));
        break;
      case ' ':
        player.fire();
        break;
      case 'p':
        pause_menu();
        break;
      default:
        break;
    }

    ppos = player.getPos();
    wattron(game_win, A_BOLD);
    mvwaddch(game_win, ppos.y, ppos.x, player.getDisp());
    wattroff(game_win, A_BOLD);
    wattron(game_win, A_ALTCHARSET);
    mvwaddch(game_win, ppos.y, ppos.x - 1, ACS_LARROW);
    mvwaddch(game_win, ppos.y, ppos.x + 1, ACS_RARROW);
    if ((tick % 10) / 3) {
      wattron(game_win, COLOR_PAIR(tick % 2 ? 3 : 4));
      mvwaddch(game_win, ppos.y + 1, ppos.x, ACS_UARROW);
      wattroff(game_win, COLOR_PAIR(tick % 2 ? 3 : 4));
    }

    wattroff(game_win, A_ALTCHARSET);
    wrefresh(main_win);
    wrefresh(game_win);
    if (exit_requested)
      break;
    else if (gameover)
      new_game();

    tick++;
    usleep(10000);  // 10 ms
  }
  close();
}

void close(void) {
  endwin();
  exit(0);
}

void info(WINDOW *info_win, int lives, int score) {
  wrefresh(info_win);
  wclear(info_win);
  mvwaddstr(info_win, 0, 1, "Life: ");
  mvwaddstr(info_win, 2, 1, "Score: ");
  mvwprintw(info_win, 2, 8, "%d", score);
  if (lives == 3)
    mvwaddstr(info_win, 0, 8, "<3  <3  <3");
  else if (lives == 2)
    mvwaddstr(info_win, 0, 8, "<3  <3");
  else if (lives == 1)
    mvwaddstr(info_win, 0, 8, "<3");
  return;
}

void new_game(void) {
  int in_char;

  wclear(main_win);
  while (1) {
    mvwaddstr(main_win, 1, 2, "Game over...");
    mvwaddstr(main_win, 3, 2, " _                  _");
    mvwaddstr(main_win, 4, 2, "( )                ( )");
    mvwaddstr(main_win, 5, 2, "(_|     __ __      |_)");
    mvwaddstr(main_win, 6, 2, "\\\'\\    /  ^  \\    /\'/");
    mvwaddstr(main_win, 7, 2, " \'\\\'\\,/\\      \\,/\'/'");
    mvwaddstr(main_win, 8, 2, "   \'\\| []   [] |/\'");
    mvwaddstr(main_win, 9, 2, "     (_  /^\\  _)");
    mvwaddstr(main_win, 10, 2, "       \\  ~  /");
    mvwaddstr(main_win, 11, 2, "       /HHHHH\\");
    mvwaddstr(main_win, 12, 2, "     /\'/{^^^}\\\'\\");
    mvwaddstr(main_win, 13, 2, " _,/\'/\'  ^^^  \'\\\'\\,_");
    mvwaddstr(main_win, 14, 2, "(_, |           | ,_)");
    mvwaddstr(main_win, 15, 2, "  (_)           (_)");
    mvwaddstr(main_win, 18, 2, "Press [R] to start a new game.");
    mvwaddstr(main_win, 19, 2, "Press [Q] or [ESC] to rage quit.");
    in_char = wgetch(main_win);
    in_char = std::tolower(in_char);
    if (in_char == 'r') break;
    if (in_char == 'q' || in_char == 27) close();
    usleep(500000);  // 500 ms
  }
  reset();
  return;
}

void pause_menu(void) {
  int in_char;

  while (1) {
    mvwaddstr(game_win, gamemin.y + (gamemax.y / 2),
              gamemin.x + (gamemax.x / 2) - 4, "P A U S E");
    in_char = wgetch(game_win);
    in_char = std::tolower(in_char);
    if (in_char == 'p') break;
  }
  return;
}

void reset(void) {
  delwin(main_win);
  delwin(game_win);
  delwin(info_win);
  init();
  run();
  return;
}
