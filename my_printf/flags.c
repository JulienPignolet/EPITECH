/*
** flags.c for flags in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  8 17:08:24 2015 Julien Pignolet
** Last update Sat Nov 14 21:22:54 2015 Julien Pignolet
*/

#include "my.h"

void	reset_struct(t_flag *flag)
{
  flag->flag_sharp = 0;
  flag->flag_zero = 0;
  flag->flag_space = 0;
  flag->flag_plus = 0;
  flag->flag_minus = 0;
}

int	try_conversion_specifier(char *format)
{
  if (*format == 'd' || *format == 'i')
    return (1);
  else if (*format == 'u' || *format == 'b' || *format == 'o'
	   || *format == 'x' || *format == 'X' || *format == 'c')
    return (2);
  else if (*format == 'p')
    return (3);
  else if (*format == 's' || *format == 'S')
    return (4);
  else if (*format == 'm' || *format == '%')
    return (5);
  else if ((*format >= 'a' && *format <= 'z') ||
	   (*format >= 'A' && *format <= 'Z'))
    return (6);
  return (0);
}

void	flag_search(t_flag *flag, char *format)
{
  (*format == '#') ? (flag->flag_sharp = 1) : (0);
  (*format == '+') ? (flag->flag_plus = 1) : (0);
  (*format == '-') ? (flag->flag_minus = 1) : (0);
  if (*format == '0' && flag->flag_zero == 0 && flag->flag_space == 0)
    while (*format >= '0' && *format <= '9')
      {
	flag->flag_zero = flag->flag_zero * 10 + (*format - 48);
	format += 1;
      }
  if (*format == ' ' && flag->flag_zero == 0 && flag->flag_space == 0)
    while (*(format + 1) >= '0' && *(format + 1) <= '9')
      {
	flag->flag_space = flag->flag_space * 10 + (*(format + 1) - 48);
	format += 1;
      }
  if ((*format >= '1' && *format <= '9') &&
      (flag->flag_plus == 1 ||flag->flag_minus == 1)
      && (flag->flag_zero == 0 && flag->flag_space == 0))
    while (*format >= '0' && *format <= '9')
      {
	flag->flag_space = flag->flag_space * 10 + (*format - 48);
	format += 1;
      }
}
