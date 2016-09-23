/*
** unsigned_int_handlers2.c for unsigned_int_handlers2 in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 17:18:19 2015 Julien Pignolet
** Last update Sun Nov  8 23:16:59 2015 Julien Pignolet
*/

#include "my.h"

void	o_handler(unsigned int nb, char *format, t_flag *flag)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (flag->flag_sharp == 1)
    j++;
  if (flag->flag_space > 0 && flag->flag_minus == 0)
    while (i + j + my_log_x(nb, OCTALE) < flag->flag_space)
      {
	my_putchar(' ');
	i++;
      }
  if (flag->flag_zero > 0 && flag->flag_minus == 0)
    while (i + j + my_log_x(nb, OCTALE) < flag->flag_zero)
      {
	my_putchar('0');
	i++;
      }
  if (flag->flag_sharp == 1)
    my_putchar('0');
  my_putnbr_base(nb, OCTALE);
  o_handler2(nb, format, flag, j);
}

void	o_handler2(unsigned int nb, char *format, t_flag *flag, int j)
{
  int	i;

  i = 0;
  if ((flag->flag_space > 0 || flag->flag_zero > 0) && flag->flag_minus == 1)
    while (i + j + my_log_x(nb, OCTALE) < flag->flag_space ||
	   i + j + my_log_x(nb, OCTALE) < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}
