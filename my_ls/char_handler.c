/*
** char_handler.c for char_handler in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 17:09:49 2015 Julien Pignolet
** Last update Fri Nov 27 10:36:19 2015 Julien Pignolet
*/

#include <stdlib.h>
#include "ls.h"

void	char_handler(char *str, char *format, t_flag *flag)
{ // %s, %S
  int	i;

  i = 0;
  if ((flag->flag_space > 0 || flag->flag_zero > 0) && flag->flag_minus == 0)
    while (i + my_strlen(str) < flag->flag_space ||
	   i + my_strlen(str) < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
  if (*format == 's')
    ((str == NULL) ? (my_putstr("(null)")) : (my_putstr(str)));
  else if (*format == 'S')
    my_print_unprintable(str);
  if ((flag->flag_space > 0 || flag->flag_zero > 0) && flag->flag_minus == 1)
    while (i + my_strlen(str) < flag->flag_space ||
	   i + my_strlen(str) < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}

void	text_handler(char *format, t_flag *flag)
{ // %%, %m
  int	i;

  i = 0;
  if ((flag->flag_space > 0 || flag->flag_zero > 0) &&
      *format == 'm' && flag->flag_minus == 0)
    while (i + 7 < flag->flag_space || i + 7 < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
  if (*format == '%')
    my_putchar('%');
  else if (*format == 'm')
    my_putstr("Success");
  if ((flag->flag_space > 0 || flag->flag_zero > 0) &&
      *format == 'm' && flag->flag_minus == 1)
    while (i + 7 < flag->flag_space || i + 7 < flag->flag_zero)
      {
	my_putchar(' ');
	i++;
      }
}
