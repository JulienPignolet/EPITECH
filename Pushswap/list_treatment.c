/*
** list_treatment.c for list_treatment in /home/pignol_j/rendu/tests/pushswap
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov 15 13:06:08 2015 Julien Pignolet
** Last update Wed Nov 18 16:51:41 2015 Julien Pignolet
*/

#include <stdlib.h>
#include "pushswap.h"

int	my_list_size(t_list *list)
{
  int	count;

  count = 0;
  while (list != NULL)
    {
      count++;
      list = list->next;
    }
  return (count);
}

int	my_put_begin_list(t_list **list, int nb)
{
  t_list	*new_nb;

  new_nb = malloc(sizeof(t_list));
  if (new_nb == NULL)
    return (1);
  new_nb->nb = nb;
  new_nb->next = *list;
  *list = new_nb;
  return (0);
}

int	my_put_end_list(t_list **list, int nb)
{
  t_list	*new_nb;
  t_list	*tamp;

  new_nb = malloc(sizeof(t_list));
  if (new_nb == NULL)
    return (1);
  new_nb->nb = nb;
  new_nb->next = NULL;
  if (*list == NULL)
    *list = new_nb;
  else
    {
      tamp = *list;
      while (tamp->next != NULL)
	tamp = tamp->next;
      tamp->next = new_nb;
    }
  return (0);
}

int	my_show_list(t_list *list)
{
  while (list != NULL)
    {
      my_put_nbr(list->nb);
      my_putchar(' ');
      list = list->next;
    }
  return (0);
}

int	my_free_list(t_list **list)
{
  t_list	*tamp_free;

  while (*list != NULL)
    {
      tamp_free = *list;
      *list = (*list)->next;
      free(tamp_free);
    }
  return (0);
}
