/*
** my_print_unprintable.c for my_print_unprintable in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sat Nov  7 18:28:05 2015 Julien Pignolet
** Last update Fri Nov 27 10:38:09 2015 Julien Pignolet
*/

#include "ls.h"

void	my_print_unprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  my_putchar('\\');
	  if (str[i] < 8)
	    my_putchar('0');
	  if (str[i] < 32)
	    my_putchar('0');
	  my_put_nbr(str[i]);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}
