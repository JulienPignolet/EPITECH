/*
** basics.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sat Mar 19 14:26:40 2016 Pignolet Julien
*/

#include "tetris.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      ++str;
    }
}

void  my_put_nbr(int nb)
{
  int d;

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

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int	my_atoi(char *nb)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  while (nb[i])
    {
      if (nb[i] >= '0' && nb[i] <= '9')
        {
          res *= 10;
          res += nb[i] - '0';
        }
      else
	return (-1);
      ++i;
    }
  return (res);
}
