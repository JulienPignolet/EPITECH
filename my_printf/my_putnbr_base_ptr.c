/*
** my_putnbr_base_ptr.c for my_putnbr_base_ptr in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sat Nov  7 16:16:34 2015 Julien Pignolet
** Last update Sat Nov  7 16:23:49 2015 Julien Pignolet
*/

#include "my.h"

void	my_putnbr_base_ptr(unsigned long int nb, char *base)
{
  unsigned long int	div;
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
