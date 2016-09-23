/*
** my_atoi.c for my_atoi in /home/pignol_j/tests/Piscine_C_evalexpr
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  1 00:11:03 2015 Julien Pignolet
** Last update Sun Nov  1 00:36:05 2015 Julien Pignolet
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

int	my_atoi(char *str)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
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
  return (res);
}
