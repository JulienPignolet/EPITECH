/*
** div.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sat Mar 19 15:33:03 2016 Pignolet Julien
*/

#include "tetris.h"

int	my_atoi_char(char nb)
{
  if (nb == '1')
    return (1);
  else if (nb == '2')
    return (2);
  else if (nb == '3')
    return (3);
  else if (nb == '4')
    return (4);
  if (nb == '5')
    return (5);
}

int	count_line(char **board, t_pos pos, t_pos old_pos)
{
  int	i;
  int	j;
  int	count;

  i = 1;
  count = 0;
  while (board[i] != NULL)
    {
      j = 1;
      while (board[i][j + 1] != '\0')
	{
	  if (COUNT_LINE)
	    {
	      j = 1;
	      ++i;
	      ++count;
	    }
	  ++j;
	}
      ++i;
    }
  return (count);
}

t_piece	gen_next(t_game	*info)
{
  int		choice;
  int		i;
  t_piece	piece;

  i = 0;
  choice = rand() % 5;
  while (i < choice)
    {
      info = info->next;
      ++i;
    }
  piece.name = info->name;
  piece.piece = info->piece;
  piece.color = info->color;
  return (piece);
}

char	*int_to_char(int nb)
{
  char	*score;
  int	d;
  int	i;

  d = 1;
  i = 0;
  score = malloc(sizeof(char) * 3000);
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  while ((nb / d) >= 10)
    d *= 10;
  while (d > 0)
    {
      score[i] = (nb / d) % 10 + '0';
      ++i;
      d /= 10;
    }
  score[i] = '\0';
  return (score);
}
