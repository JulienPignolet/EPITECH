/*
** check2.c for sudoku in /home/pignol_j/Rendu/Test/sudoku/Sudoki-Bi/Sudoki-Bi/Sudoki-Bi
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Sun Feb 28 18:39:11 2016 Pignolet Julien
** Last update Sun Feb 28 18:40:58 2016 Pignolet Julien
*/

#include "my.h"

int	check(int x_b, int y_b, char **tab, int nb)
{
  int	i;
  int	j;
  int	ret;

  ret = 0;
  while (nb < 58)
    {
      i = -1;
      while (++i != 3)
	{
	  j = 0;
	  while (j != 6)
	    {
	      (tab[i + y_b][j + x_b] == nb) ? (ret++) : (0);
	      j += 2;
	    }
	}
      if (ret > 1)
	return (28);
      ret = 0;
      ++nb;
    }
  return (0);
}

int	check_solve(char **tab)
{
  t_fako	ii;
  int		i;
  int		j;

  i = 0;
  j = 0;
  ii.i1 = check(2, 1, tab, 49);
  ii.i2 = check(8, 1, tab, 49);
  ii.i3 = check(14, 1, tab, 49);
  ii.i4 = check(2, 4, tab, 49);
  ii.i5 = check(8, 4, tab, 49);
  ii.i6 = check(14, 4, tab, 49);
  ii.i7 = check(2, 7, tab, 49);
  ii.i8 = check(8, 7, tab, 49);
  ii.i9 = check(14, 7, tab, 49);
  if (ii.i1 == 28 || ii.i2 == 28 || ii.i3 == 28 || ii.i4 == 28 || ii.i5 == 28 ||
      ii.i6 == 28 || ii.i7 == 28 || ii.i8 == 28 || ii.i9 == 28)
    return (1);
  return (0);
}

int	count_double_lin(char **tab, int y)
{
  int	count;
  int	count_tmp;
  int	nb;
  int	x;

  count = 0;
  nb = 1;
  while (nb != 10)
    {
      x = 0;
      count_tmp = 0;
      while (tab[y][x] != '\0')
	{
	  if (tab[y][x] == (nb + 48))
	    ++count_tmp;
	  ++x;
	}
      count_tmp /= 2;
      count += count_tmp;
      ++nb;
    }
  return (count);
}

int	count_double_col(char **tab, int x)
{
  int	count;
  int	count_tmp;
  int	nb;
  int	y;

  count = 0;
  nb = 1;
  while (nb != 10)
    {
      y = 1;
      count_tmp = 0;
      while (tab[y] != NULL)
	{
	  if (tab[y][x] == (nb + 48))
	    ++count_tmp;
	  ++y;
	}
      count_tmp /= 2;
      count += count_tmp;
      ++nb;
    }
  return (count);
}

int	check_no(char **tab)
{
  int	i;

  i = 1;
  if (check_solve(tab) == 1)
    return (1);
  while (i != 10)
    {
      if (count_double_lin(tab, i) != 0)
	return (1);
      ++i;
    }
  i = 2;
  while (i != 20)
    {
      if (count_double_col(tab, i) != 0)
	return (1);
      i += 2;
    }
  return (0);
}
