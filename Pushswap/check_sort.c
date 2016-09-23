/*
** check_sort.c for check_sort in /home/pignol_j/rendu/CPE_2015_Pushswap
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Fri Nov 20 14:34:58 2015 Julien Pignolet
** Last update Fri Nov 20 15:04:34 2015 Julien Pignolet
*/

#include <stdlib.h>
#include "pushswap.h"

int	check_sort(t_list **list)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = *list;
  tmp2 = *list;
  while (tmp2 != NULL)
    {
      while (tmp != NULL)
	{
	  if (tmp2->nb <= tmp->nb)
	    tmp = tmp->next;
	  else
	    return (1);
	}
      tmp2 = tmp2->next;
      tmp = tmp2;
    }
  return (0);
}
