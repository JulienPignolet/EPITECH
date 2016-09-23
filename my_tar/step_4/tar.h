/*
** tar.h for my_tar in /home/pignol_j/rendu/tests/Rush1
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Jan 10 18:27:20 2016 Julien Pignolet
** Last update Sun Jan 10 18:27:38 2016 Julien Pignolet
*/

#ifndef RUSH1_TAR_H
#define RUSH1_TAR_H

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ftw.h>
#include <stdio.h>
#include <unistd.h>
#include <utime.h>

typedef struct __attribute__((packed)) s_header
{
  char name[100];
  char mode[8];
  char uid[8];
  char gid[8];
  char size[12];
  char mtime[12];
  char checksum[8];
  char type[1];
  char link[100];
  char padding[255];
} t_header;

typedef struct s_params
{
  int x;
  int v;
  int f;
  int c;
  int t;
  int p;
  int index_start;
} t_params;

FILE *out;
t_params *params;


char           *get_file_right(__mode_t mode);
void	       set_file_attribute(t_header header, char *file);
t_params       *init_params(t_params *params);
int	       parse_params(int ac, char **av);
void	       fill_block(FILE *stream, int size);
t_header       parse_header(char *header, t_params *params);
void	       print_tvf(t_header header);

#endif //RUSH1_TAR_H
