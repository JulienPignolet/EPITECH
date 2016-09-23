/*
** ai.c for allum1 in /home/pignol_j/Rendu/CPE_2015_Allum1
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Fri Feb 12 19:48:18 2016 Pignolet Julien
** Last update Wed Feb 17 15:01:46 2016 Pignolet Julien
*/

#include "my.h"

t_allum	my_calc(t_allum allum)
{
  int	match;
  int	xor;
  int	tot;
  int	i;
  int	line;

  xor = allum.l1 ^ allum.l2 ^ allum.l3 ^ allum.l4;
  i = 0;
  WIN;
  while (xor != 0)
    {
      AI;
      ++i;
    }
  my_putstr("AI removed ");
  my_put_nbr(match);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
  return (allum);
}

t_allum my_hard_ai(t_allum allum)
{
  my_putstr("AI's turn...\n");
  allum = my_calc(allum);
  my_board(allum);
  return (allum);
}
