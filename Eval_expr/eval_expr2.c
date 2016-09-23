/*
** eval_expr2.c for eval_expr2 in /home/pignol_j/rendu/Piscine_C_evalexpr
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct 22 00:42:27 2015 julien pignolet
** Last update Thu Oct 22 18:11:21 2015 Arthur HAKOBIAN
*/

#include <stdlib.h>
#include "./include/my.h"

int     my_getnbr_inf(char *str)
{
  int   i;
  int   k;
  int   nb;

  i = 0;
  k = 0;
  nb = 0;
  if (str[i] == '-')
    {
      k = 1;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb *= 10;
      nb += (str[i] - '0');
      i++;
      if (nb < 0)
        return (0);
    }
  if (k == 1)
    return (-nb);
  return (nb);
}

int     number(char **str)
{
  char  *nb;
  int	value;

  nb = *str;
  if (**str == '-' && *(*str + 1) == '(')
    {
      *str += 2;
      value = summands(str);
      *str += 1;
      return (-value);
    }
  if (**str == '(')
    {
      *str += 1;
      value = summands(str);
      *str += 1;
      return (value);
    }
  my_strtol(*str, str);
  return (my_getnbr_inf(nb));
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
  while (str[i] >= '0' && str[i] <= '9')
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
  res = malloc(sizeof(*res) * (my_strlen(str) + 1));
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
  return (res);
}
