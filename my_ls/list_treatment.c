/*
** list_treatment.c for list_treatment in /home/pignol_j/rendu/tests/my_ls
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Fri Nov 20 20:58:57 2015 Julien Pignolet
** Last update Fri Nov 27 13:05:54 2015 Julien Pignolet
*/

#include "ls.h"

void	swap_elem_list(t_list *elem1, t_list *elem2)
{
  char	c_tamp;
  char	*s_tamp;
  int	i_tamp;

  s_tamp = elem1->name;
  elem1->name = elem2->name;
  elem2->name = s_tamp;
  c_tamp = elem1->type;
  elem1->type = elem2->type;
  elem2->type = c_tamp;
  c_tamp = elem1->r_owner;
  elem1->r_owner = elem2->r_owner;
  elem2->r_owner = c_tamp;
  c_tamp = elem1->w_owner;
  elem1->w_owner = elem2->w_owner;
  elem2->w_owner = c_tamp;
  c_tamp = elem1->x_owner;
  elem1->x_owner = elem2->x_owner;
  elem2->x_owner = c_tamp;
  c_tamp = elem1->r_group;
  elem1->r_group = elem2->r_group;
  elem2->r_group = c_tamp;
  swap_elem_list2(elem1, elem2);
}

void	swap_elem_list2(t_list *elem1, t_list *elem2)
{
  char	c_tamp;
  char	*s_tamp;
  int	i_tamp;

  c_tamp = elem1->w_group;
  elem1->w_group = elem2->w_group;
  elem2->w_group = c_tamp;
  c_tamp = elem1->x_group;
  elem1->x_group = elem2->x_group;
  elem2->x_group = c_tamp;
  c_tamp = elem1->r_other;
  elem1->r_other = elem2->r_other;
  elem2->r_other = c_tamp;
  c_tamp = elem1->w_other;
  elem1->w_other = elem2->w_other;
  elem2->w_other = c_tamp;
  c_tamp = elem1->x_other;
  elem1->x_other = elem2->x_other;
  elem2->x_other = c_tamp;
  i_tamp = elem1->nlink;
  elem1->nlink = elem2->nlink;
  elem2->nlink = i_tamp;
  swap_elem_list3(elem1, elem2);
}

void	swap_elem_list3(t_list *elem1, t_list *elem2)
{
  char	c_tamp;
  char	*s_tamp;
  int	i_tamp;

  s_tamp = elem1->username;
  elem1->username = elem2->username;
  elem2->username = s_tamp;
  s_tamp = elem1->groupname;
  elem1->groupname = elem2->groupname;
  elem2->groupname = s_tamp;
  i_tamp = elem1->size;
  elem1->size = elem2->size;
  elem2->size = i_tamp;
  s_tamp = elem1->day;
  elem1->day = elem2->day;
  elem2->day = s_tamp;
}

void	sort_ascii_list(t_list *list)
{
  int		sort;
  char		*tamp;
  char		*s1;
  char		*s2;
  t_list	*tmp;

  while (list != NULL)
    {
      sort = 0;
      while (sort == 0)
	{
	  tmp = list;
	  sort = 1;
	  while (tmp != NULL)
	    {
	      STRDUP;
	      (my_strcmp(s1, s2) > 0) ?
		(swap_elem_list(list, tmp), sort = 0) : (0);
	      free(s1);
	      free(s2);
	      tmp = tmp->next;
	    }
	}
      list = list->next;
    }
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
