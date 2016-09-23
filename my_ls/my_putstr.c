/*
** my_putstr.c for my_putstr in /home/pignol_j/rendu/Piscine_C_J04
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct  1 10:44:12 2015 julien pignolet
** Last update Fri Nov 27 10:40:20 2015 Julien Pignolet
*/

#include "ls.h"

void	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
