/*
** my_putnbr_base.c for my_puynbr_base in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sat Nov  7 12:40:41 2015 Julien Pignolet
** Last update Fri Nov 27 10:38:43 2015 Julien Pignolet
*/

#include "ls.h"

void	my_putnbr_base(unsigned int nb, char *base)
{
  unsigned int	div;
  int	n_base;

  div = 1;
  n_base = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  while ((nb / div) >= n_base)
    div *= n_base;
  while (div > 0)
    {
      my_putchar(base[(nb / div) % n_base]);
      div /= n_base;
    }
}
