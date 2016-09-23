/*
** basics.c for my_select in /home/pignol_j/rendu/PSU_2015_my_select
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Tue Dec  8 19:12:29 2015 Julien Pignolet
** Last update Tue Dec  8 19:17:46 2015 Julien Pignolet
*/

#include "ms.h"

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

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}
