/*
** my_log_x.c for my_log16 in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 15:16:03 2015 Julien Pignolet
** Last update Sun Nov  8 17:01:05 2015 Julien Pignolet
*/

#include "my.h"

int	my_log_x(unsigned int nb, char *base)
{
  unsigned int	div;
  int	count;
  int	n_base;

  div = 1;
  count = 0;
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
      count++;
      div /= n_base;
    }
  return (count);
}
