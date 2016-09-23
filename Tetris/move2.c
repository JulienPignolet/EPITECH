/*
** move2.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sat Mar 19 16:45:47 2016 Pignolet Julien
*/

#include "tetris.h"

int	check_lose(t_pos pos, char **board)
{
  if (board[pos.y1][pos.x1] != ' ')
    return (-1);
  if (board[pos.y2][pos.x2] != ' ')
    return (-1);
  if (board[pos.y3][pos.x3] != ' ')
    return (-1);
  if (board[pos.y4][pos.x4] != ' ')
    return (-1);
  return (0);
}

t_pos	init_pos(t_piece piece, char **board, int col)
{
  t_pos	pos;

  INIT_POS;
  return (pos);
}

t_pos	turn_t(t_piece *t, t_pos pos, t_pos old_pos, char **board)
{
  t_pos	new_pos;

  new_pos = pos;
  if (t->turn == 1)
    TURN_T1;
  else if (t->turn == 2)
    TURN_T2;
  else if (t->turn == 3)
    TURN_T3;
  else if (t->turn == 4)
    TURN_T4;
    if (check_border(board, new_pos, old_pos) == 0)
      {
	(t->turn == 4) ? (t->turn = 1) : (++t->turn);
	return (new_pos);
      }
    return (pos);
}

t_pos	turn_z(t_piece *z, t_pos pos, t_pos old_pos, char **board)
{
  t_pos	new_pos;

  new_pos = pos;
  if (z->turn % 2 == 1)
    TURN_Z;
  else if (z->turn % 2 == 0)
    {
      new_pos.x1 = pos.x3 + 1;
      new_pos.y1 = pos.y3 + 1;
      new_pos.x2 = pos.x3;
      new_pos.y2 = pos.y3 + 1;
      new_pos.x4 = pos.x3 - 1;
      new_pos.y4 = pos.y3;
    }
  if (check_border(board, new_pos, old_pos) == 0)
    {
      (z->turn == 4) ? (z->turn = 1) : (++z->turn);
      return (new_pos);
    }
  return (pos);
}

t_pos	turn(t_piece *current, t_pos pos, t_pos old_pos, char **board)
{
  if (current->name == 'i')
    return (turn_i(current, pos, old_pos, board));
  else if (current->name == 'l')
    return (turn_l(current, pos, old_pos, board));
  else if (current->name == 't')
    return (turn_t(current, pos, old_pos, board));
  else if (current->name == 'z')
    return (turn_z(current, pos, old_pos, board));
  return (pos);
}
