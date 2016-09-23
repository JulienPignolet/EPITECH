/*
** basics.c for allum1 in /home/pignol_j/Rendu/CPE_2015_Allum1
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Fri Feb 12 19:45:54 2016 Pignolet Julien
** Last update Sat Feb 20 12:33:43 2016 Pignolet Julien
*/

#include "my.h"

void	my_putchar_error(char c)
{
  write(1, &c, 1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr_error(char *str)
{
  while (*str)
    {
      my_putchar_error(*str);
      str += 1;
    }
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str += 1;
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
