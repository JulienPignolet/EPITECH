/*
** my_put_nbr_pos.c for my_put_nbr_pos in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sat Nov  7 18:10:12 2015 Julien Pignolet
** Last update Sun Nov  8 17:01:55 2015 Julien Pignolet
*/

#include "my.h"

void	my_put_nbr_pos(unsigned int nb)
{
  unsigned int   d;

  d = 1;
  while ((nb / d) >= 10)
    d *= 10;
  while (d > 0)
    {
      my_putchar((nb / d) % 10 + '0');
      d /= 10;
    }
}
