/*
** unsigned_int_handlers.c for unsigned_int_handlers in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 17:13:44 2015 Julien Pignolet
** Last update Sun Nov  8 23:08:21 2015 Julien Pignolet
*/

#include "my.h"

void	u_handler(unsigned int nb, char *format, t_flag *flag)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (flag->flag_space > 0 && flag->flag_minus == 0)
    while (i + j + my_log10(nb) < flag->flag_space)
      {
	my_putchar(' ');
	i++;
      }
  if (flag->flag_zero > 0 && flag->flag_minus == 0)
    while (i + j + my_log10(nb) < flag->flag_zero)
      {
	my_putchar('0');
	i++;
      }
  my_put_nbr_pos(nb);
  if ((flag->flag_space > 0 || flag->flag_zero > 0) && flag->flag_minus == 1)
    while (i + j + my_log10(nb) < flag->flag_space ||
	   i + j + my_log10(nb) < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}

void	b_handler(unsigned int nb, char *format, t_flag *flag)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (flag->flag_sharp == 1)
    j++;
  if (flag->flag_space > 0 && flag->flag_minus == 0)
    while (i + j + my_log_x(nb, BINAIRE) < flag->flag_space)
      {
	my_putchar(' ');
	i++;
      }
  if (flag->flag_sharp == 1)
    my_putchar('0');
  if (flag->flag_zero > 0 && flag->flag_minus == 0)
    while (i + j + my_log_x(nb, BINAIRE) < flag->flag_zero)
      {
	my_putchar('0');
	i++;
      }
  my_putnbr_base(nb, BINAIRE);
  b_handler2(nb, format, flag, j);
}

void	b_handler2(unsigned int nb, char *format, t_flag *flag, int j)
{
  int	i;

  i = 0;
  if ((flag->flag_zero > 0 || flag->flag_space > 0) && flag->flag_minus == 1)
    while (i + j + my_log_x(nb, BINAIRE) < flag->flag_space ||
	   i + j + my_log_x(nb, BINAIRE) < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}

void	c_handler(unsigned int nb, char *format, t_flag *flag)
{
  int	i;

  i = 0;
  if ((flag->flag_space > 0 || flag->flag_zero > 0) && flag->flag_minus == 0)
    while (i + 1 < flag->flag_space || i + 1 < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
  my_putchar(nb);
  if ((flag->flag_space > 0 || flag->flag_zero > 0) && flag->flag_minus == 1)
    while (i + 1 < flag->flag_space || i + 1 < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}
