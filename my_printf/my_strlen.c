/*
** my_strlen.c for my_strlen in /home/pignol_j/rendu/Piscine_C_J04
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct  1 11:14:23 2015 julien pignolet
** Last update Sat Nov  7 13:11:09 2015 Julien Pignolet
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return i;
}
