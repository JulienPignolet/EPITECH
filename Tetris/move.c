/*
** move.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sat Mar 19 16:38:03 2016 Pignolet Julien
*/

#include "tetris.h"

int	check_border(char **board, t_pos pos, t_pos old_pos)
{
  if (board[pos.y1][pos.x1] == '-')
    return (1);
  else if (board[pos.y2][pos.x2] == '-')
    return (1);
  else if (board[pos.y3][pos.x3] == '-')
    return (1);
  else if (board[pos.y4][pos.x4] == '-')
    return (1);
  if (board[pos.y1][pos.x1] == '|')
    return (1);
  else if (board[pos.y2][pos.x2] == '|')
    return (1);
  else if (board[pos.y3][pos.x3] == '|')
    return (1);
  else if (board[pos.y4][pos.x4] == '|')
    return (1);
  else if (CB1)
    return (1);
  else if (CB2)
    return (1);
  else if (CB3)
    return (1);
  else if (CB4)
    return (1);
  return (0);
}

t_pos	check_border2(char **board, t_pos pos, t_pos old_pos, int plus)
{
  t_pos	new_pos;

  new_pos = pos;
  if (plus == 1)
    {
      ++new_pos.x1;
      ++new_pos.x2;
      ++new_pos.x3;
      ++new_pos.x4;
      if (check_border(board, new_pos, old_pos) == 0)
	return (new_pos);
    }
  else
    {
      --new_pos.x1;
      --new_pos.x2;
      --new_pos.x3;
      --new_pos.x4;
      if (check_border(board, new_pos, old_pos) == 0)
	return (new_pos);
    }
  return (pos);
}

t_pos	down_pos(t_pos pos)
{
  ++pos.y1;
  ++pos.y2;
  ++pos.y3;
  ++pos.y4;
  return (pos);
}

t_pos	turn_i(t_piece	*i, t_pos pos, t_pos old_pos, char **board)
{
  t_pos	new_pos;

  new_pos = pos;
  if (i->turn % 2 == 1)
    TURN_I;
  else if (i->turn % 2 == 0)
    {
      new_pos.x1 = pos.x2 - 1;
      new_pos.y1 = pos.y2;
      new_pos.x3 = pos.x2 + 1;
      new_pos.y3 = pos.y2;
      new_pos.x4 = pos.x2 + 2;
      new_pos.y4 = pos.y2;
    }
  if (check_border(board, new_pos, old_pos) == 0)
    {
      (i->turn == 4) ? (i->turn = 1) : (++i->turn);
      return (new_pos);
    }
  return (pos);
}

t_pos	turn_l(t_piece *l, t_pos pos, t_pos old_pos, char **board)
{
  t_pos	new_pos;

  new_pos = pos;
  TURN_L;
  if (check_border(board, new_pos, old_pos) == 0)
    {
      (l->turn == 4) ? (l->turn = 1) : (++l->turn);
      return (new_pos);
    }
  return (pos);
}
