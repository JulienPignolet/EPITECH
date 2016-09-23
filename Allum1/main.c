/*
** main.c for allum1 in /home/pignol_j/Rendu/CPE_2015_allum1_bootstrap
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Wed Feb 10 22:38:38 2016 Pignolet Julien
** Last update Sun Feb 21 01:11:13 2016 Pignolet Julien
*/

#include "my.h"

void	my_game(t_allum allum)
{
  int	line;
  int	match;
  int	i;
  char	*buf;
  char	*tmp;
  char	tmpr[1];

  my_board(allum);
  while (1) {
    INIT;
    while (match == -1 || match == 0) {
      INIT_BIS;
      while (line == -1) { INIT2;
	while (tmpr[0] != '\n')
	  READ1;
	line = set_line(allum, line);
      } INIT3;
      while (tmpr[0] != '\n')
	READ2;
      match = set_match(allum, match, line);
    } RMV;
    if (check_end(allum, "You lost, too bad..\n") == 1)
      return;
    allum = my_hard_ai(allum);
  }
}

int	main()
{
  t_allum	allum;

  allum.l1 = 1;
  allum.l2 = 3;
  allum.l3 = 5;
  allum.l4 = 7;
  my_game(allum);
  return (0);
}
