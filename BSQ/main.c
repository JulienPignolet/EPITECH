/*
** main.c for BSQ in /home/pignol_j/rendu/tests/BSQ
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Mon Dec 14 12:09:09 2015 Julien Pignolet
** Last update Mon Dec 21 20:16:31 2015 Julien Pignolet
*/

#include "bsq.h"

int	check_bsq(char **tab, t_pos *pos, int x, int y, int width, int height)
{
  int	i;
  int	j;

  i = pos->y;
  j = pos->x;
  while ((i != (pos->y + y)) || (j != (pos->x + x)))
    {
      while (j <= (pos->x + x))
	{
	  if (((pos->x + x) >= width) ||
	      ((pos->y + y) >= height) || (tab[i][j] == 'o'))
	    return (1);
	  ++j;
	}
      if ((i != (pos->y + y)) || (j != (pos->x + x + 1)))
	{
	  ++i;
	  j = pos->x;
	}
      else
	--j;
    }
  return (0);
}

char	**bsq(char **tab, char *buffer)
{
  int		i;
  int		j;
  int		x;
  int		y;
  t_pos		*pos;
  t_save	*save;

  SET_VAR;
  if (((pos = malloc(sizeof(t_pos))) == NULL)
      || ((save = malloc(sizeof(t_save))) == NULL))
    return (NULL);
  init_struct(pos, save);
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
	{
	  INIT_BSQ;
	  while ((check_bsq(tab, pos, x, y,
			    count_c(buffer, i), count_l(buffer)) == 0))
	    ((x > save->x && y > save->y) ? (SET_SAVE, INCR_BSQ) : (INCR_BSQ));
	  ++j;
	}
      DEINCR_BSQ;
    }
  return (write_bsq(tab, save));
}

char	**tab_1_x(char **tab, int *s_i, int *s_j, int *passage)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == '.' && *passage == 0)
	    {
	      tab[i][j] = 'x';
	      *passage = 1;
	      *s_i = i;
	      *s_j = j;
	    }
	  ++j;
	}
      ++i;
      j = 0;
    }
  return (tab);
}

char	**write_bsq(char **tab, t_save *save)
{
  int	i;
  int	j;
  int	s_i;
  int	s_j;
  int	passage;

  i = save->pos_y;
  j = save->pos_x;
  passage = 0;
  s_i = 0;
  s_j = 0;
  tab = tab_1_x(tab, &s_i, &s_j, &passage);
  while ((i != save->pos_y + save->y) || (j != save->pos_x + save->x))
    {
      while (j <= (save->pos_x + save->x))
	{
	  (passage == 1) ? (tab[s_i][s_j] = '.', passage = 0) : (0);
	  tab[i][j] = 'x';
	  ++j;
	}
      (((i != save->pos_y + save->y) ||
	(j != save->pos_x + save->x + 1)) ? (++i, j = save->pos_x) : (--j));
    }
  return (tab);
}

int	main(int argc, char **argv)
{
  char	**tab;

  if (argc == 2)
    {
      tab = my_file_to_tab(argv[1]);
      if (tab != NULL)
	my_show_tab(tab);
      free(tab);
    }
  return (0);
}
