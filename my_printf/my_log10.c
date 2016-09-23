/*
** my_log10.c for my_log10 in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 10:26:50 2015 Julien Pignolet
** Last update Sun Nov  8 15:04:48 2015 Julien Pignolet
*/

#include "my.h"

int	my_log10(unsigned int nb)
{
  int	res;

  res = 0;
  while (nb / 10 > 0)
    {
      res++;
      nb /= 10;
    }
  return (res + 1);
}
