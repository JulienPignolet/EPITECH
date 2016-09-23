/*
** main.c for Pushswap in /home/pignol_j/rendu/tests/pushswap
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Wed Nov 11 20:20:28 2015 Julien Pignolet
** Last update Fri Nov 20 15:04:44 2015 Julien Pignolet
*/

#include <stdlib.h>
#include "pushswap.h"

int	main(int argc, char **argv)
{
  int	i;
  int	sort;
  int	bonus;
  t_list	*list1;
  t_list	*list2;
  
  INIT;
  (argc == 2) ? (my_putchar('\n')) : (0);
  if (argc > 2)
    {
      ((argv[1][0] == '-' && argv[1][1] == 'v') ? (i = 2, bonus = 1) : (i = 1));
      while (i < argc)
  	{
  	  (my_atoi_error(argv[i]) == 0) ?
  	    (my_put_end_list(&list1, my_atoi(argv[i])), sort = 1) : (0);
  	  i++;
  	}
      ((check_sort(&list1) == 0) ? (my_putchar('\n')) :
       ((sort == 1) ? my_pushswap(&list1, &list2, bonus) : (0)));
      my_free_list(&list1);
      my_free_list(&list2);
    }
}
