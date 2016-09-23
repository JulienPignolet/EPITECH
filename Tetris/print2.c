/*
** main.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sun Mar 20 14:07:35 2016 Pignolet Julien
*/

#include "tetris.h"

void	my_debug(t_option option, t_game *game)
{
  mvprintw(1, 1, "*** DEBUG MODE ***");
  DEBUG_K;
  DEBUG;
}

void	my_high_score(t_score score)
{
  int		i;
  static int	k = 1;

  ((score.sec % 10) == 0 && k == 0) ? (k = 1) : (0);
  ((score.sec % 10) != 0) ? (k = 0) : (0);
  i = 1;
  mvprintw(8, 1, "/");
  while (++i < 22)
    mvprintw(8, i, "-");
  MHS;
  i = 1;
  while (++i < 22)
    mvprintw(18, i, "-");
  mvprintw(18, i, "/");
  mvprintw(22, 1, "Tetris du boss (c) - 2015");
}

void	tetriminos(t_game **game)
{
  t_piece	piece1;
  t_piece	piece2;
  t_piece	piece3;
  t_piece	piece4;
  t_piece	piece5;

  TTR;
}

int	read_hscore()
{
  int	score;
  int	fd;
  char	buf[3000];

  fd = open("score", O_RDONLY);
  read(fd, buf, 2999);
  score = my_atoi(buf);
  close(fd);
  return (score);
}

void	write_hscore(int score)
{
  int	fd;
  char	*buf;

  fd = open("score", O_WRONLY);
  buf = int_to_char(score);
  write(fd, buf, my_strlen(buf));
  close(fd);
}
