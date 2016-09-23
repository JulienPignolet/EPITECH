/*
** eval_expr.c for eval_expr in /home/pignol_j/rendu/Piscine_C_evalexpr
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Wed Oct 21 09:14:11 2015 julien pignolet
** Last update Wed Nov  4 17:26:39 2015 Arthur Hakobian
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

char	*summands(char **str)
{
  char	*res;

  res = factors(str);
  while (**str != '\0' && **str != ')')
    {
      if ((**str >= '0' && **str <= '9') ||
	  **str == '+' || **str == '-' || **str == '(')
	res = main_add_inf(res, factors(str), 0, 0);
      else
	**str += 1;
    }
  return (res);
}

char	*factors(char **str)
{
  char	*res;

  res = number(str);
  while (**str != '\0' && **str != ')')
    {
      if (**str == '-')
	return (res);
      if (**str == '+')
	{
	  *str += 1;
	  return (res);
	}
      (**str == '*') ? (*str += 1, res = infin_mult(res, number(str))) :
	((**str == '/') ? (*str += 1, res = infin_div(res, number(str))) :
	 ((**str == '%') ? (*str += 1, res = infin_mod(res, number(str))) :
	  (*str += 1)));
    }
  return (res);
}

char	*eval_expr(char *base, char *ops, char *av, unsigned int size)
{
  char	*str;

  str = my_strdup(av);
  str = my_str_nospace(str);
  str = stand(str, 0, 0, 0);
  return (summands(&str));
}

int	main(int ac, char **av)
{
  char	*expr;
  unsigned int	size;

   if (ac != 4)
     {
       my_putstr("Usage : ./calc base operators size_read");
       return (1);
     }
   else
    {
      size = my_atoi(av[3]);
      expr = get_expr(size);
      my_putstr(eval_expr(av[1], av[2], expr, size));
    }
  return (0);
}
