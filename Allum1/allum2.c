/*
** allum2.c for allum1 in /home/pignol_j/Rendu/CPE_2015_Allum1
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Fri Feb 12 19:50:39 2016 Pignolet Julien
** Last update Sun Feb 21 01:17:15 2016 Pignolet Julien
*/

#include "my.h"

int	check_end(t_allum allum, char *msg)
{
  if (allum.l1 == 0 && allum.l2 == 0 && allum.l3 == 0 && allum.l4 == 0)
    {
      my_putstr(msg);
      return (1);
    }
  return (0);
}

t_allum	set_allum(t_allum allum, int match, int line)
{
  if (line == 1)
    allum.l1 -= match;
  else if (line == 2)
    allum.l2 -= match;
  else if (line == 3)
    allum.l3 -= match;
  else if (line == 4)
    allum.l4 -= match;
  return (allum);
}

void	my_board(t_allum allum)
{
  my_putstr("*********\n");
  (allum.l1 == 1) ? (my_putstr("*   |   *\n")) :
    (my_putstr("*       *\n"));
  (allum.l2 == 3) ? (my_putstr("*  |||  *\n")) :
    ((allum.l2 == 2) ? (my_putstr("*  ||   *\n")) :
     ((allum.l2 == 1) ? (my_putstr("*  |    *\n")) :
      (my_putstr("*       *\n"))));
  (allum.l3 == 5) ? (my_putstr("* ||||| *\n")) :
    ((allum.l3 == 4) ? (my_putstr("* ||||  *\n")) :
     ((allum.l3 == 3) ? (my_putstr("* |||   *\n")) :
      ((allum.l3 == 2) ? (my_putstr("* ||    *\n")) :
       ((allum.l3 == 1) ? (my_putstr("* |     *\n")) :
	(my_putstr("*       *\n"))))));
  (allum.l4 == 7) ? (my_putstr("*|||||||*\n")) :
    ((allum.l4 == 6) ? (my_putstr("*|||||| *\n")) :
     ((allum.l4 == 5) ? (my_putstr("*|||||  *\n")) :
      ((allum.l4 == 4) ? (my_putstr("*||||   *\n")) :
       ((allum.l4 == 3) ? (my_putstr("*|||    *\n")) :
	((allum.l4 == 2) ? (my_putstr("*||     *\n")) :
	 ((allum.l4 == 1) ? (my_putstr("*|      *\n")) :
	  (my_putstr("*       *\n"))))))));
  my_putstr("*********\n");
  if (check_end(allum, "") != 1)
    my_putchar('\n');
}
