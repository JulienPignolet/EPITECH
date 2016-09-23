/*
** unsigned_long_int_handler.c for unsigned_long_int_handler in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 17:07:07 2015 Julien Pignolet
** Last update Sun Nov  8 22:28:32 2015 Julien Pignolet
*/

#include "my.h"

void	unsigned_long_int_handler(unsigned long int nb, t_flag *flag)
{ // %p
  int	i;
  int	j;

  i = 0;
  j = 0;
  (flag->flag_plus == 1) ? (j = 1) : (0);
  if (flag->flag_space > 0 && flag->flag_minus == 0)
    while (i + j +  14 < flag->flag_space)
      {
	my_putchar(' ');
	i++;
      }
  (flag->flag_plus == 1) ? (my_putchar('+')) : (0);
  my_putstr("0x");
  if (flag->flag_zero > 0 && flag->flag_minus == 0)
    while (i + j + 14 < flag->flag_zero)
      {
	my_putchar('0');
	i++;
      }
  my_putnbr_base_ptr(nb, HEXA_MIN);
  unsigned_long_int_hand2(nb, flag, i, j);
}

void	unsigned_long_int_hand2
(unsigned long int nb, t_flag *flag, int i, int j)
{
  if ((flag->flag_space > 0 || flag->flag_zero > 0) && flag->flag_minus == 1)
    while (i + j +  14 < flag->flag_space || i + j +  14 < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}
