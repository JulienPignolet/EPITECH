/*
** check.c for sudoku in /home/pignol_j/Rendu/Test/sudoku/Sudoki-Bi/Sudoki-Bi/Sudoki-Bi
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Sun Feb 28 18:38:27 2016 Pignolet Julien
** Last update Sun Feb 28 18:40:45 2016 Pignolet Julien
*/

#include "my.h"

int	check_in(t_list *list, int x, int y)
{
  while (list != NULL)
    {
      if (list->x == x && list->y == y)
	return (1);
      list = list->next;
    }
  return (0);
}

int	check_error(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if ((i == 0 || i == 10) && j != 0 && j != 19 && tab[i][j] != '-')
	    return (1);
	  else if ((j == 0 || j == 19) && tab[i][j] != '|')
	    return (1);
	  else if ((tab[i][j] < '1' || tab[i][j] > '9') &&
		   tab[i][j] != ' ' && i > 0 && i < 10 && j > 0 && j < 19)
	    return (1);
	  ++j;
	}
      if (j != 20)
	return (1);
      ++i;
    }
  if (i != 11)
    return (1);
  return (0);
}

int	check_line(char **tab, int y, int x, char nb)
{
  int	i;

  i = 0;
  while (tab[y][i] != '\0')
    {
      if (tab[y][i] == nb && i != x)
	return (1);
      ++i;
    }
  return (0);
}

int	check_col(char **tab, int x, int y, char nb)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i][x] == nb && i != y)
	return (1);
      ++i;
    }
  return (0);
}

int	check_case(char **tab, int x, int y, char nb)
{
  int	x2;
  int	y2;
  int	i;
  int	j;

  SET_POS;
  i = y2;
  while (i <= (y2 + 2))
    {
      j = x2;
      while (j <= (x2 + 4))
	{
	  if (tab[i][j] == nb && i != y && j != x)
	    return (1);
	  ++j;
	}
      ++i;
    }
  return (0);
}
