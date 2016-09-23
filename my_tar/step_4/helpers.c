/*
** helpers.c for helpers in /home/pignol_j/rendu/tests/Rush1
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Jan 10 18:16:40 2016 Julien Pignolet
** Last update Sun Jan 10 18:16:43 2016 Julien Pignolet
*/

#include "tar.h"

t_params *init_params(t_params *params)
{
  params = malloc(sizeof(t_params));
  params->x = 0;
  params->f = 0;
  params->c = 0;
  params->p = 0;
  params->t = 0;
  params->v = 0;
  params->index_start = 0;
  return (params);
}

void fill_block(FILE *stream, int size)
{
  int i;

  i = 0;
  while (i < size)
    {
      fputc(0, stream);
      i++;
    }
}

void print_tvf(t_header header)
{
  char *endptr;
  long value;
  char buff[100];

  value = strtol(header.mode, &endptr, 8);
  printf("%s\t", get_file_right((__mode_t) value));
  value = strtol(header.uid, &endptr, 8);
  printf("%lu\\", value);
  value = strtol(header.gid, &endptr, 8);
  printf("%lu\t", value);
  value = strtol(header.size, &endptr, 8);
  printf("%lu\t", value);
  value = strtol(header.mtime, &endptr, 8);
  strftime (buff, 100, "%Y-%m-%d %H:%M", localtime (&value));
  printf("%s\t%s\n", buff, header.name);
}
