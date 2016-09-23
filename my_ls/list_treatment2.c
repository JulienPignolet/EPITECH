/*
** list_treatment2.c for list_treatment2.c in /home/pignol_j/rendu/tests/my_ls
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Fri Nov 27 13:14:20 2015 Julien Pignolet
** Last update Sun Nov 29 19:58:12 2015 Julien Pignolet
*/

#include "ls.h"

int	my_put_in_list(t_list **list, t_dirent *entry, char *way,
		       t_option *option)
{
  t_list	*new_elem;
  t_stat	check;

  if (stat(my_strcat(my_strcat(way, "/"), entry->d_name) , &check) == -1)
    {
      my_printf("File not found\n");
      return (1);
    }
  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return (1);
  new_elem->name = entry->d_name;
  my_put_in_list2(check, new_elem, option);
  new_elem->next = *list;
  *list = new_elem;
  return (0);
}

int	my_put_in_list2(t_stat check, t_list *new_elem, t_option *option)
{
  if (option->o_l == 1)
    {
      ((S_ISDIR(check.st_mode)) ? (new_elem->type = 'd') :
       ((S_ISREG(check.st_mode)) ? (new_elem->type = '-') :
	((S_ISCHR(check.st_mode)) ? (new_elem->type = 'c') :
	 ((S_ISBLK(check.st_mode)) ? (new_elem->type = 'b') :
	  ((S_ISLNK(check.st_mode)) ? (new_elem->type = 'l') :
	   ((S_ISFIFO(check.st_mode)) ? (new_elem->type = 'f') :
	    ((S_ISSOCK(check.st_mode)) ? (new_elem->type = 's') :
	     (0))))))));
      R_RUSR;
      R_WUSR;
      R_XUSR;
      R_RGRP;
      R_WGRP;
      R_XGRP;
      R_ROTH;
      R_WOTH;
      R_XOTH;
      new_elem->day = my_time(my_strdup(ctime(&check.st_mtime)));
      new_elem->nlink = check.st_nlink;
      new_elem->username = my_strdup(getpwuid(check.st_uid)->pw_name);
      new_elem->groupname = my_strdup(getgrgid(check.st_gid)->gr_name);
      new_elem->size = check.st_size;
    }
}

int	my_put_in_name(t_name	**name, char *str)
{
  t_name	*new_elem;
  t_name	*tamp;

  if ((new_elem = malloc(sizeof(t_name))) == NULL)
    return (1);
  new_elem->name = str;
  new_elem->next = NULL;
  if (*name == NULL)
    *name = new_elem;
  else
    {
      tamp = *name;
      while (tamp->next != NULL)
	tamp = tamp->next;
      tamp->next = new_elem;
    }
  return (0);
}
void	my_show_list(t_list *list, t_option *option, char *way)
{
  ((option->o_l == 1) ? (my_printf("total 42\n")) :(0));
  while (list != NULL)
    {
      ((list->name[0] == '.' && list->name[1] == '\0' && option->o_d == 1) ?
       (((option->o_l == 1) ? (my_printf("%c%c%c%c%c%c%c%c%c%c %i %s %s %i %s ",
					 list ->type, list->r_owner, list->w_owner, list->x_owner,
					 list->r_group, list->w_group, list->x_group, list->r_other,
					 list->w_other, list->x_other, list->nlink, list->username,
					 list->groupname, list->size, list->day)) : (0)),
	my_printf("%s\n", way), exit(1)) : (0));
      while (list->name[0] == '.' && option->o_a != 1)
	if ((list = list->next) == NULL)
	  exit(1);
      if (option->o_l == 1)
	{
	  my_printf("%c%c%c%c%c%c%c%c%c%c %i %s %s %i %s ",
		    list ->type, list->r_owner, list->w_owner, list->x_owner,
		    list->r_group, list->w_group, list->x_group,
		    list->r_other, list->w_other, list->x_other,
		    list->nlink, list->username, list->groupname,
		    list->size, list->day);
	}
      my_printf("%s\n", list->name);
      list = list->next;
    }
}

int	my_name_size(t_name *name)
{
  int	count;

  count = 0;
  while (name != NULL)
    {
      count++;
      name = name->next;
    }
  return (count);
}

