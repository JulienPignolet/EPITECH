/*
** get_expr.c for get_expr in /home/pignol_j/tests/Piscine_C_evalexpr
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  1 00:20:17 2015 Julien Pignolet
** Last update Sun Nov  1 14:00:12 2015 Julien Pignolet
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

char	*get_expr(unsigned int size)
{
  char	*expr;

  if (size <= 0)
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      exit(2);
    }
  expr = malloc(size + 1);
  if (expr == 0)
    {
      my_putstr(ERROR_MSG);
      exit(3);
    }
  if (read(0, expr, size) != size)
    {
      my_putstr(ERROR_MSG);
      exit(4);
    }
  expr[size] = 0;
  return (expr);
}
