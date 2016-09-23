/*
** basics.c for BSQ in /home/pignol_j/rendu/CPE_2015_BSQ
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Tue Dec 15 15:41:48 2015 Julien Pignolet
** Last update Wed Dec 16 11:33:08 2015 Julien Pignolet
*/

#include "bsq.h"

int	my_strlen(char *str)
{
  int	i;

  while (str[i] != '\0')
    ++i;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str += 1;
    }
}

void	init_struct(t_pos *pos, t_save *save)
{
  pos->x = 0;
  pos->y = 0;
  save->x = -1;
  save->y = -1;
  save->pos_x = 0;
  save->pos_y = 0;
}
