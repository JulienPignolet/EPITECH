/*
** main.c for sudoku in /home/pignol_j/Rendu/Test/sudoku
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Sat Feb 27 17:26:32 2016 Pignolet Julien
** Last update Sun Feb 28 18:40:31 2016 Pignolet Julien
*/

#include "my.h"

int	my_ai(char **tab, t_list *list)
{
  int	i;
  int	j;

  INIT;
  while (i != 10) {
    CHECK;
    while (CHECK2) {
      (tab[i][j] == ' ') ? (tab[i][j] = '0') : (0);
      while (tab[i][j] == '9') {
	while (check_in(list, j, i) == 1)
	  (j == 2) ? (--i, j = 18) : (j-= 2);
	tab[i][j] = ' ';
	(j == 2) ? (--i, j = 18) : (j -= 2);
	while (check_in(list, j, i) == 1)
	  (j == 2) ? (--i, j = 18) : (j-= 2);
      } ++tab[i][j];
    } j += 2;
  }
  tab[10][2] = '-';
  show_tab(tab);
  return (0);
}

int	main()
{
  int		i;
  int		j;
  int		first;
  int		size;
  char		buf[230];
  char		**tab;
  t_list	*list;

  first = 0;
  while ((size = read(0, buf, 231)) > 0) { INIT2;
    while (tab[i] != NULL) { j = 0;
      while (tab[i][j] != '\0') { if (tab[i][j] >= '1' && tab[i][j] <= '9')
	  my_put_in_list(&list, j, i);
	++j;
      } ++i;
    } if (check_error(tab) == 1) { printf("MAP ERROR\n");
      return (1);
    } else if (check_no(tab) == 1)
      aff_err();
    else
      if (my_ai(tab, list) == 1)
	return (1);
    FREE;
  }
  return (0);
}
