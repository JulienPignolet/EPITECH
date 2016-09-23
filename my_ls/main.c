/*
** main.c for my_files in /home/pignol_j/rendu/tests/my_ls
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Fri Nov 20 18:01:51 2015 Julien Pignolet
** Last update Sun Nov 29 19:56:41 2015 Julien Pignolet
*/

#include "ls.h"

char	*my_time(char *str)
{
  char	*res;

  if ((res = malloc(sizeof(char) * 12)) == NULL)
    return (NULL);
  res[0] = str[4];
  res[1] = str[5];
  res[2] = str[6];
  res[3] = str[7];
  res[4] = str[8];
  res[5] = str[9];
  res[6] = str[10];
  (str[20] == '2' && str[21] == '0' && str[22] == '1' && str[23] == '5') ?
    (res[7] = str[11], res[8] = str[12], res[9] = str[13],
     res[10] = str[14], res[11] = str[15], res[12] = '\0') :
    (res[7] = str[20], res[8] = str[21], res[9] = str[22],
     res[10] = str[23], res[11] = '\0');
  return (res);
}

int	my_ls1(t_dirent *entry, t_list *list, t_option *option)
{
  DIR		*dirp;

  if ((dirp = opendir(".")) == NULL)
    return (1);
  while ((entry = readdir(dirp)) != NULL)
    my_put_in_list(&list, entry, ".", option);
  sort_ascii_list(list);
  my_show_list(list, option, ".");
  closedir(dirp);
  return (0);
}

int	my_ls2(t_dirent *entry, t_list *list, t_option *option, t_name *name)
{
  DIR		*dirp;
  int		size;

  size = my_name_size(name);
  while (name != NULL)
    {
      if (size > 1)
	my_printf("%s:\n", name->name);
      if ((dirp = opendir(name->name)) == NULL)
	return (1);
      while ((entry = readdir(dirp)) != NULL)
	my_put_in_list(&list, entry, name->name, option);
      sort_ascii_list(list);
      my_show_list(list, option, name->name);
      my_free_list(&list);
      name = name->next;
      if (name != NULL)
	my_printf("\n");
    }
  closedir(dirp);
  return (0);
}

int	main(int argc, char **argv)
{
  t_dirent	*entry;
  t_list	*list;
  t_option	*option;
  t_name	*name;
  int	i;

  list = NULL;
  name = NULL;
  option = malloc(sizeof(t_option));
  init_option(option);
  i = 1;
  while (i < argc)
    {
      (argv[i][0] == '-') ? (check_option(argv[i], option)) :
	(my_put_in_name(&name, argv[i]));
      i++;
    }
  if (argc == 1 || (argc == 2 && argv[1][0] == '-'))
    my_ls1(entry, list, option);
  else
    my_ls2(entry, list, option, name);
  return (0);
}
