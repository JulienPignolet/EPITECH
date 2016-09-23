/*
** print.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sat Mar 19 16:17:34 2016 Pignolet Julien
*/

#include "tetris.h"

void	my_show_board(char **board)
{
  int	i;
  int	j;
  int	y;
  int	x;

  i = 0;
  y = 1;
  while (board[i] != NULL)
    {
      x = 30;
      j = 0;
      while (board[i][j])
  	{
	  SHOW;
  	  ++x;
	  ++j;
  	}
      ++y;
      ++i;
    }
}

void	my_next(int col, t_piece current)
{
  mvprintw(1, (38 + col), "/Next--\\");
  mvprintw(2, (38 + col), "|");
  mvprintw(3, (38 + col), "|");
  mvprintw(2, (45 + col), "|");
  mvprintw(3, (45 + col), "|");
  mvprintw(4, (38 + col), "\\------/");
  NEXT;
}

char	**my_board(int row, int col)
{
  char	**board;
  int	i;
  int	j;

  i = 0;
  if ((board = malloc(sizeof(char *) * (row + 3))) == NULL)
    return (NULL);
  while (i < (row + 2))
    {
      j = 1;
      if ((board[i] = malloc(sizeof(char) * (col + 3))) == NULL)
	return (NULL);
      board[i][0] = (i == 0 || i == row + 1) ? ('-') : ('|');
      while (j < (col + 1 ))
	{
	  board[i][j] = (i == 0 || i == row + 1) ? ('-') : (' ');
	  ++j;
	}
      board[i][j] = (i == 0 || i == row + 1) ? ('-') : ('|');
      board[i][j + 1] = '\0';
      ++i;
    }
  board[i] = NULL;
  return (board);
}

void	my_title()
{
  TITLE;
}

void	my_help()
{
  my_putstr("Usage: ./tetris [options]\n");
  my_putstr("Options:\n");
  my_putstr("  --help\t\tDisplay this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num\n");
  my_putstr("  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}\tSet default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}\tQuit program when press key K\n");
  my_putstr("  -kp --key-pause={K}\tPause and restart game when press key K\n");
  my_putstr("  --map-size={row,col}\tSet game size at row, col\n");
  my_putstr("  -w --without-next\tHide next tetrimino\n");
  my_putstr("  -d --debug\t\tDebug mode\n");
}
