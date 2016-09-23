/*
** unsigned_int_handlers3.c for unsigned_int_handlers3 in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 23:16:10 2015 Julien Pignolet
** Last update Sun Nov  8 23:22:05 2015 Julien Pignolet
*/

#include "my.h"

void	x_handler(unsigned int nb, char *format, t_flag *flag)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (flag->flag_sharp == 1)
    j += 2;
  if (flag->flag_space > 0 && flag->flag_minus == 0)
    while (i + j + my_log_x(nb, HEXA_MIN) < flag->flag_space)
      {
	my_putchar(' ');
	i++;
      }
  if (flag->flag_sharp == 1)
    my_putstr("0x");
  if (flag->flag_zero > 0 && flag->flag_minus == 0)
    while (i + j + my_log_x(nb, HEXA_MIN) < flag->flag_zero)
      {
	my_putchar('0');
	i++;
      }
  my_putnbr_base(nb, HEXA_MIN);
  x_handler2(nb, format, flag, j);
}

void	x_handler2(unsigned int nb, char *format, t_flag *flag, int j)
{
  int	i;

  i = 0;
  if ((flag->flag_space > 0 || flag->flag_zero > 0) && flag->flag_minus == 1)
    while (i + j + my_log_x(nb, HEXA_MIN) < flag->flag_space ||
	   i + j + my_log_x(nb, HEXA_MIN) < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}

void	X_handler(unsigned int nb, char *format, t_flag *flag)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (flag->flag_sharp == 1)
    j += 2;
  if (flag->flag_space > 0 && flag->flag_minus == 0)
    while (i + j + my_log_x(nb, HEXA_MAJ) < flag->flag_space)
      {
	my_putchar(' ');
	i++;
      }
  if (flag->flag_sharp == 1)
    my_putstr("0X");
  if (flag->flag_zero > 0 && flag->flag_minus == 0)
    while (i + j + my_log_x(nb, HEXA_MAJ) < flag->flag_zero)
      {
	my_putchar('0');
	i++;
      }
  my_putnbr_base(nb, HEXA_MAJ);
  X_handler2(nb, format, flag, j);
}

void	X_handler2(unsigned int nb, char *format, t_flag *flag, int j)
{
  int	i;

  i = 0;
  if ((flag->flag_space > 0 || flag->flag_zero) && flag->flag_minus == 1)
    while (i + j + my_log_x(nb, HEXA_MAJ) < flag->flag_space ||
	   i + j + my_log_x(nb, HEXA_MAJ) < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}
