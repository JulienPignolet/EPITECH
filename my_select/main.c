/*
** main.c for my_select in /home/pignol_j/rendu/PSU_2015_my_select
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Dec  3 10:58:56 2015 Julien Pignolet
** Last update Mon Dec 14 14:28:19 2015 Julien Pignolet
*/

#include "ms.h"

void	my_cadre()
{
  int	i;

  i = 2;
  while (i < LINES - 1)
    {
      mvprintw(i, 1, "|");
      mvprintw(i, COLS - 1, "|");
      ++i;
    }
  i = 3;
  while (i < COLS - 2)
    {
      mvprintw(LINES - 1, i, "-");
      mvprintw(1, i, "-");
      ++i;
    }
  mvprintw(1, 1, "+");
  mvprintw(LINES - 1, 1, "+");
  mvprintw(LINES - 1, COLS - 1, "+");
  mvprintw(1, COLS - 1, "+");
  mvprintw(1, ((COLS / 2) - 6), "[MY_SELECT]");
}

void	my_select2(t_list **list, int *stop)
{
  int		x;
  int		y;
  int		clavier;
  t_list	*tamp;

  tamp = *list;
  x = 3;
  y = 2;
  while (*stop == 0 && ((clavier = getch()) != 27))
    {
      clear();
      my_cadre();
      K_UP;
      K_DOWN;
      K_SPACE;
      K_SUPPR;
      K_ENTRY;
      x = tamp->c_x;
      y = tamp->c_y;
      my_show_list(list, stop);
      mvprintw(y, x, "X");
      refresh();
    }
}

void	my_select(t_list **list)
{
  int		stop;
  FILE		*file;
  SCREEN	*screen;

  stop = 0;
  file = fopen("/dev/tty", "w+");
  screen = newterm("xterm", file, file);
  set_term(screen);
  curs_set(0);
  keypad(stdscr, TRUE);
  noecho();
  clear();
  my_cadre();
  (*list)->current = 1;
  my_show_list(list, &stop);
  ((stop == 0) ? (mvprintw(2, 4, "X"), my_select2(list, &stop)) : (0));
  echo();
  endwin();
  if (stop == 2)
    my_show_select(list);
  if (stop == 1)
    my_putstr("La fenêtre est trop petite\n");
}

int	main(int argc, char **argv)
{
  t_list	*list;
  int		i;

  i = 1;
  list = NULL;
  while (i < argc)
    {
      my_putend_list(&list, argv[i]);
      ++i;
    }
  if (list != NULL)
    my_select(&list);
  return (0);
}
