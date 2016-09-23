/*
** infin_mult.c for infin_mult in /home/pignol_j/rendu/Piscine_C_infinmult
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Fri Oct 23 17:28:02 2015 julien pignolet
** Last update Sun Nov  1 17:57:33 2015 Julien Pignolet
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

char	*remove0(char *str)
{
  char	*res;
  int	i;
  int	j;
  int	count_sign;

  i = 0;
  j = 0;
  count_sign = 0;
  res = malloc(sizeof(*res) * (my_strlen(str) + 1));
  while (str[i] == '0' && str[i + 1] != '\0')
    i++;
  while (str[i] != '\0')
    {
      res[j] = str[i];
      i++;
      j++;
    }
  return (res);
}

char   *infin_mult2(char *nb1, char *nb2)
{
  char  *res;
  int	tamp;
  int	i;
  int	j;

  res = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 1));
  res = my_memset(res, (my_strlen(nb1) + my_strlen(nb2)));
  res[my_strlen(nb1) + my_strlen(nb2)] = 0;
  i = my_strlen(nb1) - 1;
  while (i >= 0)
    {
      j = my_strlen(nb2) - 1;
      while (j >= 0)
        {
	  tamp = (nb1[i] - '0') * (nb2[j] - '0');
          res[i + j] += ((res[i + j + 1] + tamp - '0') / 10);
          res[i + j + 1] = ((res[i + j + 1] + tamp - '0') % 10) + '0';
	  j--;
        }
      i--;
    }
  return (remove0(res));
}

char	*infin_mult(char *nb1, char *nb2)
{
  char	*res;

  if (nb1[0] == '-' && nb2[0] != '-' || nb1[0] != '-' && nb2[0] == '-')
    {
      nb1 = my_removeminus(nb1);
      nb2 = my_removeminus(nb2);
      res = my_add_to_str2("-", infin_mult2(nb1, nb2));
      return (res);
    }
  else
    {
      nb1 = my_removeminus(nb1);
      nb2 = my_removeminus(nb2);
      return (infin_mult2(nb1, nb2));
    }
}
