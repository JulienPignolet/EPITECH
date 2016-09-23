/*
** display.c for display in /home/pignol_j/rendu/tests/pushswap
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov 15 13:19:53 2015 Julien Pignolet
** Last update Sun Nov 15 13:31:52 2015 Julien Pignolet
*/

#include <unistd.h>
#include "pushswap.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

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

