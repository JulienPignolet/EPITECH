/*
** parsing.c for parsing in /home/pignol_j/rendu/tests/Rush1
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Jan 10 18:16:25 2016 Julien Pignolet
** Last update Sun Jan 10 18:16:28 2016 Julien Pignolet
*/

#include "tar.h"

t_header parse_header(char *header, t_params *params)
{
  t_header my_struct;
  struct stat st = {0};
  char *endptr;
  long value;

  strncpy(my_struct.name, header, 100);
  strncpy(my_struct.mode, header + 100, 108);
  strncpy(my_struct.uid, header + 108, 116);
  strncpy(my_struct.gid, header + 116, 124);
  strncpy(my_struct.size, header + 124, 136);
  strncpy(my_struct.mtime, header + 136, 148);
  strncpy(my_struct.checksum, header + 148, 156);
  strncpy(my_struct.type, header + 156, 157);
  if (my_struct.type[0] == '5' && stat(my_struct.name, &st) == -1)
    {
      value = strtol(my_struct.mode, &endptr, 8);
      mkdir(my_struct.name, (__mode_t) value);
    }
  if ((params->x && params->v) || (params->t && !params->v))
    printf("%s\n", my_struct.name);
  else if (params->t && params->v && params->f)
    print_tvf(my_struct);
  return (my_struct);
}

int parse_params(int ac, char **av)
{
  int i;
  int j;

  i = 1;
  while (i < ac)
    {
      j = 1;
      if (av[i][0] == '-')
	{
	  while (av[i][j])
	    {
	      (av[i][j] == 'x') ? params->x = 1 : 0;
	      (av[i][j] == 'v') ? params->v = 1 : 0;
	      (av[i][j] == 'f') ? params->f = 1 : 0;
	      (av[i][j] == 't') ? params->t = 1 : 0;
	      (av[i][j] == 'c') ? params->c = 1 : 0;
	      j++;
	    }
	}
      else
	{
	  params->index_start = i;
	  return (1);
	}
      i++;
    }
}
