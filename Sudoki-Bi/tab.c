/*
** tab.c for sudoku in /home/pignol_j/Rendu/Test/sudoku
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Sat Feb 27 17:28:08 2016 Pignolet Julien
** Last update Sat Feb 27 17:30:58 2016 Pignolet Julien
*/

#include "my.h"

char	**str_tab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  tab = malloc(sizeof(char *) * (strlen(str) + 1));
  while (str[k])
    {
      j = 0;
      tab[i] = malloc(sizeof(char) * (strlen(str) + 1));
      while (str[k] != '\n' && str[k])
	{
	  tab[i][j] = str[k];
	  ++k;
	  ++j;
	}
      (str[k] != '\0') ? (++k) : (0);
      tab[i][j] = '\0';
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s\n", tab[i]);
      ++i;
    }
}
