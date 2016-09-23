/*
** list.c for my_select in /home/pignol_j/rendu/PSU_2015_my_select
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Tue Dec  8 19:14:32 2015 Julien Pignolet
** Last update Wed Dec  9 16:52:18 2015 Julien Pignolet
*/

#include "ms.h"

void	my_putend_list(t_list **list, char *name)
{
  t_list	*new_elem;
  t_list	*tamp;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    exit(1);
  new_elem->name = name;
  if (*list == NULL)
    {
      *list = new_elem;
      new_elem->prev = *list;
      new_elem->next = *list;
    }
  else
    {
      tamp = *list;
      while (tamp->next != *list)
	tamp = tamp->next;
      tamp->next = new_elem;
      new_elem->prev = tamp;
      new_elem->next = *list;
      (*list)->prev = new_elem;
    }
}

void	my_show_list(t_list **list, int *stop)
{
  t_list	*tamp;
  int		i;
  int		x;
  int		y;
  int		len_max;

  len_max = 0;
  x = 3;
  y = 2;
  i = 1;
  tamp = *list;
  while (tamp != *list || i == 1)
    {
      tamp->c_x = x + 1;
      tamp->c_y = y;
      mvprintw(y, x, "[ ]");
      TEXT;
      ((my_strlen(tamp->name) > len_max) ?
       (len_max = my_strlen(tamp->name)) : (0));
      tamp = tamp->next;
      y += 2;
      ((y > LINES - 2) ? (y = 2, x += len_max + 6,
			  ((x > COLS - 8) ? (*stop = 1) : (0))) : (0));
      i = 0;
    }
}

void	my_show_select(t_list **list)
{
  int		i;
  int		passage;
  t_list	*tamp;

  tamp = *list;
  passage = 0;
  i = 1;
  while (tamp != *list || i == 1)
    {
      if (tamp->select == 1)
	{
	  if (passage == 1)
	    my_putchar(' ');
	  my_putstr(tamp->name);
	  passage = 1;
	}
      tamp = tamp->next;
      i = 0;
    }
  if (passage == 1)
    my_putchar('\n');
}
