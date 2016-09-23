/*
** my_stand.c for stand in /home/pignol_j/tests/Piscine_C_evalexpr
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Nov  1 20:59:43 2015 Julien Pignolet
** Last update Sun Nov  1 22:56:34 2015 Arthur Hakobian
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

char	*stand(char *s, int i, int j, int count)
{
  int	check;
  int	ok;
  char	*res;

  res = malloc(sizeof(char) * (my_strlen(s) + 1));
  while (s[i] != '\0')
    {
      ok = 0;
      check = 0;
      count = 0;
      while (s[i] == '-' || s[i] == '+')
	{
	  (s[i - 1] == '/' || s[i - 1] == '*' || s[i - 1] == '%') ?
	    (check = 1) : (0);
	  (s[i] == '-') ? (count++) : (0);
	  i++;
	  ok = 1;
	}
      (check == 1) ? (0) :
	((count % 2 == 0 && ok == 1 && j != 0) ? (res[j] = '+', j++) :
	 ((count % 2 == 0 && ok == 1 && j == 0) ? (0) :
	  ((count % 2 != 0 && ok == 1) ? (res[j] = '-', j++) :
	   (res[j] = s[i], i++, j++))));
    }
  return (res);
}
