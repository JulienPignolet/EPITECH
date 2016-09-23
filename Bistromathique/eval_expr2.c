/*
** eval_expr2.c for eval_expr2 in /home/pignol_j/rendu/Piscine_C_evalexpr
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct 22 00:42:27 2015 julien pignolet
** Last update Sun Nov  1 20:15:18 2015 Julien Pignolet
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

char	*my_stack_nbr(char *str)
{
  char	*res;
  int   i;
  int   j;

  i = 0;
  j = 0;
  res = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (str[i] == '-')
    {
      res[j] = '-';
      j++;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      res[j] = str[i];
      j++;
      i++;
    }
  res[my_strlen(str)] = 0;
  return (res);
}

char	*number(char **str)
{
  char  *nb;
  char	*value;

  nb = *str;
  if (**str == '-' && *(*str + 1) == '(')
    {
      *str += 2;
      value = my_add_to_str2("-", summands(str));
      *str += 1;
      return (value);
    }
  if (**str == '(')
    {
      *str += 1;
      value = summands(str);
      *str += 1;
      return (value);
    }
  my_strtol(*str, str);
  return (my_stack_nbr(nb));
}

int     my_strtol(char *str, char **endptr)
{
  int   i;

  i = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      *endptr += 1;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9' && str[i + 1] != '\0')
    {
      *endptr += 1;
      i++;
    }
  return (0);
}

char    *my_str_nospace(char *str)
{
  char  *res;
  int   i;
  int   j;

  i = 0;
  j = 0;
  res = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (res == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] != ' ')
        {
          res[j] = str[i];
          j++;
        }
      i++;
    }
  res[my_strlen(str)] = 0;
  return (res);
}
