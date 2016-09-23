/*
** move3.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sun Mar 20 14:11:33 2016 Pignolet Julien
*/

#include "tetris.h"

char	**my_remove(char **board, int i)
{
  int	j;

  while (i != 2)
    {
      j = 0;
      while (board[i][j] != '\0')
	{
	  board[i][j] = board[i - 1][j];
	  ++j;
	}
      --i;
    }
  return (board);
}

char	**check_remove(char **board, int *score, int *lr)
{
  int	erase;
  int	i;
  int	j;

  i = 1;
  while (board[i + 1] != NULL)
    {
      erase = 1;
      j = 0;
      while (board[i][j] != '\0')
	{
	  if (board[i][j] == ' ')
	    erase = 0;
	  ++j;
	}
      (erase == 1) ? (board = my_remove(board, i), *score += 50, ++(*lr)) : (0);
      ++i;
    }
  return (board);
}

char	**set_pos(char **board, t_pos pos, t_pos old_pos, t_piece current)
{
  board[old_pos.y1][old_pos.x1] = ' ';
  board[old_pos.y2][old_pos.x2] = ' ';
  board[old_pos.y3][old_pos.x3] = ' ';
  board[old_pos.y4][old_pos.x4] = ' ';
  board[pos.y1][pos.x1] = (current.color == 1) ?
    ('1') : ((current.color == 2) ? ('2') :
	     ((current.color == 3) ? ('3') :
	      ((current.color == 4) ? ('4') : ('5'))));
  board[pos.y2][pos.x2] = board[pos.y1][pos.x1];
  board[pos.y3][pos.x3] = board[pos.y1][pos.x1];
  board[pos.y4][pos.x4] = board[pos.y1][pos.x1];
  return (board);
}

int	match(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '=' && s1[i] != '\0')
    {
      if (s2[i] != s1[i])
	return (0);
      ++i;
    }
  return (1);
}
