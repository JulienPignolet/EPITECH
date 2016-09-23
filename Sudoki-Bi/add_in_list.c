/*
** add_in_list.c for lists in /home/hakobi_a/rendu/CPE_2015_Allum1
**
** Made by hakobi_a
** Login   <hakobi_a@epitech.net>
**
** Started on  Thu Feb 18 11:33:48 2016 hakobi_a
** Last update Sun Feb 28 11:54:12 2016 Pignolet Julien
*/

#include "my.h"

int	my_put_in_list(t_list **list, int x, int y)
{
  t_list	*elem;
  t_list	*tmpa;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->x = x;
  elem->y = y;
  elem->next = NULL;
  if (*list == NULL)
    {
      *list = elem;
      return (0);
    }
  tmpa = *list;
  while (tmpa->next != NULL)
    tmpa = tmpa->next;
  tmpa->next = elem;
  return (0);
}
