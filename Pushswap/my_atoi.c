/*
** my_atoi.c for my_atoi in /home/pignol_j/tests/Piscine_C_evalexpr
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  1 00:11:03 2015 Julien Pignolet
** Last update Sun Nov 15 13:17:58 2015 Julien Pignolet
*/

#include <stdlib.h>
#include "pushswap.h"

int	my_atoi(char *str)
{
  int	res;
  int	sign;
  int	i;

  res = 0;
  sign = 0;
  i = 0;
  ((str[i] == '-') ? (sign = 1, i++) : (0));
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  res *= 10;
	  res += str[i] - '0';
	}
      else
	return (res);
      i++;
    }
  if (sign == 0)
    return (res);
  else
    return (-res);
}

int	my_atoi_error(char *str)
{
  while (*str != '\0')
    {
      if ((*str < '0' || *str > '9') && *str != '-')
	return (1);
      str += 1;
    }
  return (0);
}
