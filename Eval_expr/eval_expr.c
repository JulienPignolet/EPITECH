/*
** eval_expr.c for eval_expr in /home/pignol_j/rendu/Piscine_C_evalexpr
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Wed Oct 21 09:14:11 2015 julien pignolet
** Last update Thu Oct 22 17:35:18 2015 Arthur HAKOBIAN
*/

#include <stdlib.h>
#include "./include/my.h"

char	*my_str_nospace(char *);

int	summands(char **str)
{
  int	res;

  res = factors(str);
  while (**str != '\0' && **str != ')')
    ((**str >= '0' && **str <= '9') || **str == '+' || **str == '-'
     || **str == '(') ? (res += factors(str)) : (**str += 1);
  return (res);
}

int	factors(char **str)
{
  int	res;

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
      (**str == '*') ? (*str += 1, res *= number(str)) : (0);
      (**str == '/') ? (*str += 1, res /= number(str)) : (0);
      (**str == '%') ? (*str += 1, res %= number(str)) : (0);
    }
  return (res);
}

int	eval_expr(char *av)
{
  char	*str;

  str = my_strdup(av);
  str = my_str_nospace(str);
  return (summands(&str));
}

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      my_put_nbr(eval_expr(av[1]));
      my_putchar('\n');
    }
  return (0);
}
