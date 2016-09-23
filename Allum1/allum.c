/*
** allum.c for allum1 in /home/pignol_j/Rendu/CPE_2015_Allum1
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Fri Feb 12 19:49:18 2016 Pignolet Julien
** Last update Fri Feb 12 19:49:49 2016 Pignolet Julien
*/

#include "my.h"

int	get_line(char *line)
{
  int	res;

  res = my_getnbr(line);
  if (res == -1)
    {
      my_putstr_error("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  else if (res < 1 || res > 4)
    {
      my_putstr_error("Error: this line is out of range\n");
      return (-1);
    }
  return (res);
}

int	set_line(t_allum allum, int line)
{
  if (line == 1 && allum.l1 == 0)
    {
      my_putstr_error("Error: this line is empty\n");
      return (-1);
    }
  else if (line == 2 && allum.l2 == 0)
    {
      my_putstr_error("Error: this line is empty\n");
      return (-1);
    }
  else if (line == 3 && allum.l3 == 0)
    {
      my_putstr_error("Error: this line is empty\n");
      return (-1);
    }
  else if (line == 4 && allum.l4 == 0)
    {
      my_putstr_error("Error: this line is empty\n");
      return (-1);
    }
  return (line);
}

int	get_match(char *match)
{
  int	res;

  res = my_getnbr(match);
  if (res == 0)
    {
      my_putstr_error("Error: you have to remove at least one match\n");
      return (-1);
    }
  else if (res == -1)
    {
      my_putstr_error("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  return (res);
}

int	set_match(t_allum allum, int match, int line)
{
  if (line == 1 && match > allum.l1)
    {
      my_putstr_error("Error: not enough matches on this line\n");
      return (-1);
    }
  else if (line == 2 && match > allum.l2)
    {
      my_putstr_error("Error: not enough matches on this line\n");
      return (-1);
    }
  else if (line == 3 && match > allum.l3)
    {
      my_putstr_error("Error: not enough matches on this line\n");
      return (-1);
    }
  else if (line == 4 && match > allum.l4)
    {
      my_putstr_error("Error: not enough matches on this line\n");
      return (-1);
    }
  return (match);
}

int	check_line(t_allum allum, int line)
{
  if (line == 1 && allum.l1 == 0)
    return (-1);
  if (line == 2 && allum.l2 == 0)
    return (-1);
  if (line == 3 && allum.l3 == 0)
    return (-1);
  if (line == 4 && allum.l4 == 0)
    return (-1);
  return (line);
}
