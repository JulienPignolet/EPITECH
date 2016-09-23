/*
** my_printf_test.c for my_printf in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sat Nov  7 20:09:09 2015 Julien Pignolet
** Last update Sat Nov 14 21:51:38 2015 Julien Pignolet
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_printf(char *format, ...)
{
  va_list	ap;
  t_flag	*flag;

  flag = malloc(sizeof(t_flag));
  if (flag == NULL || format == NULL)
    return (0);
  va_start(ap, format);
  while (*format != '\0')
    if (*format == '%')
      {
	RESET;
	while (TEST0 && *format != '\0')
	  SEARCH;
	(TEST1 ? (int_handler(va_arg(ap, int), flag), format += 1) :
	 (TEST2 ? (UIH(va_arg(ap, unsigned int), format, flag), format += 1) :
	  (TEST3 ? (UILH(va_arg(ap, unsigned long int), flag), format += 1) :
	   (TEST4 ? (char_handler(va_arg(ap, char *), format, flag), format += 1) :
	    (TEST5 ? (text_handler(format, flag), format += 1) :
	     (TEST6 ? (my_putchar('%')) : (0)))))));
      }
    else
      DISPLAY;
  free(flag);
  va_end(ap);
  return (1);
}
