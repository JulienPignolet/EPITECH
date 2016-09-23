/*
** my_putstr.c for my_putstr in /home/pignol_j/rendu/Piscine_C_J04
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct  1 10:44:12 2015 julien pignolet
** Last update Sat Nov  7 13:12:54 2015 Julien Pignolet
*/

#include "my.h"

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
