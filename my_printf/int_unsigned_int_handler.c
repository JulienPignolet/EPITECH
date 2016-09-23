/*
** int_unsigned_int_handler.c for int_unsigned_int_handler in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 17:11:17 2015 Julien Pignolet
** Last update Sun Nov  8 23:26:02 2015 Julien Pignolet
*/

#include "my.h"

void	unsigned_int_handler(unsigned int nb, char *format, t_flag *flag)
{ // %X, %x, %o, %u, %b, %c
  if (*format == 'u')
    u_handler(nb, format, flag);
  else if (*format == 'b')
    b_handler(nb, format, flag);
  else if (*format == 'c')
    c_handler(nb, format, flag);
  else if (*format == 'o')
    o_handler(nb, format, flag);
  else if (*format == 'x')
    x_handler(nb, format, flag);
  else if (*format == 'X')
    X_handler(nb, format, flag);
}

void	int_handler(int nb, t_flag *flag)
{ // %d, %i
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (flag->flag_plus == 1 && nb >= 0)
    j = 1;
  if (flag->flag_space > 0 && flag->flag_minus == 0)
    while (i + j + my_log10(nb) < flag->flag_space)
      {
	my_putchar(' ');
	i++;
      }
  if (flag->flag_plus == 1 && nb >= 0)
    my_putchar('+');
  if (flag->flag_zero > 0 && flag->flag_minus == 0)
    while (i + j + my_log10(nb) < flag->flag_zero)
      {
	my_putchar('0');
	i++;
      }
  my_put_nbr(nb);
  int_handler2(nb, flag, i, j);
}

void	int_handler2(int nb, t_flag *flag, int i, int j)
{
  if ((flag->flag_space > 0 || flag->flag_zero) && flag->flag_minus == 1)
    while (i + j + my_log10(nb) < flag->flag_space ||
	   i + j + my_log10(nb) < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}
