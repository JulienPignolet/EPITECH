/*
** my_putnbr.c for my_putnbr in /home/pignol_j/rendu/test
**
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
**
** Started on  Thu Oct  1 18:16:13 2015 julien pignolet
** Last update Thu Feb 11 10:40:03 2016 Pignolet Julien
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int   d;

  d = 1;
  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb *= -1;
	}
      while ((nb / d) >= 10)
	d *= 10;
      while (d > 0)
	{
	  my_putchar((nb / d) % 10 + '0');
	  d /= 10;
	}
    }
}
