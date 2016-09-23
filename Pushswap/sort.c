/*
** sort.c for sort in /home/pignol_j/rendu/tests/pushswap
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov 15 13:08:17 2015 Julien Pignolet
** Last update Thu Nov 19 19:59:55 2015 Julien Pignolet
*/

#include <stdlib.h>
#include "pushswap.h"

void	push(t_list **list1, t_list **list2)
{
  int		nb;
  t_list	*tamp_free;

  nb = (*list1)->nb;
  my_put_begin_list(list2, nb);
  tamp_free = *list1;
  *list1 = (*list1)->next;
  free(tamp_free);
}

void	rotate(t_list **list1)
{
  int		nb;
  t_list	*tamp_free;

  nb = (*list1)->nb;
  my_put_end_list(list1, nb);
  tamp_free  = *list1;
  *list1 = (*list1)->next;
  free(tamp_free);
}

int	my_calc_push(t_list *list)
{
  int	count;
  int	count2;
  int	nb;

  count = 0;
  count2 = 0;
  nb = list->nb;
  while (list != NULL)
    {
      if ((list->nb) < nb)
	{
	  nb = list->nb;
	  count = count2;
	}
      list = list->next;
      count2++;
    }
  return (count);
}

void	my_pushswap2(t_list **list1, t_list **list2, int bonus)
{
  int	i;
  int	j;

  i = 0;
  if (my_list_size(*list1) != 1)
    {
      j = my_calc_push(*list1);
      while (i < j)
	{
	  ROTATE;
	  ((bonus == 1) ? (my_putstr("ra\nl_a "), my_show_list(*list1),
			   my_putstr("\nl_b "), my_show_list(*list2),
			   my_putchar('\n')) : (my_putstr("ra ")));
	  i++;
	}
      PUSH;
      ((bonus == 1) ? (my_putstr("pb\nl_a "), my_show_list(*list1),
		       my_putstr("\nl_b "), my_show_list(*list2),
		       my_putchar('\n')) : (my_putstr("pb ")));
      my_pushswap2(list1, list2, bonus);
    }
}

void	my_pushswap(t_list **list1, t_list **list2, int bonus)
{
  int	i;

  my_pushswap2(list1, list2, bonus);
  i  = my_list_size(*list2);
  while (i > 0)
    {
      POP;
      i--;
      if (i > 0)
	((bonus == 1) ? (my_putstr("pa\nl_a "), my_show_list(*list1),
			 my_putstr("\nl_b "),  my_show_list(*list2),
			 my_putchar('\n')) : (my_putstr("pa ")));
      else
	((bonus == 1) ? (my_putstr("pa\nl_a "), my_show_list(*list1),
			 my_putstr("\nl_b "), my_show_list(*list2),
			 my_putchar('\n')) : (my_putstr("pa\n")));
    }
}
