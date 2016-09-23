/*
** add_in_list.c for lists in /home/hakobi_a/rendu/CPE_2015_Allum1
**
** Made by hakobi_a
** Login   <hakobi_a@epitech.net>
**
** Started on  Thu Feb 18 11:33:48 2016 hakobi_a
** Last update Sat Mar 19 15:33:37 2016 Pignolet Julien
*/

#include <stdlib.h>
#include "tetris.h"

int	add_list(t_game **list, t_piece piece)
{
  t_game	*elem;
  t_game	*tmpa;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->name = piece.name;
  elem->x = piece.L;
  elem->y = piece.l;
  elem->color = piece.color;
  elem->piece = piece.piece;
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
