/*
** infin_mod.c for infin mod in /home/nauroy_s/Piscine_C_infindiv
** 
** Made by Sylvain Nauroy-Béthune
** Login   <nauroy_s@epitech.net>
** 
** Started on  Sun Nov  1 09:58:28 2015 Sylvain Nauroy-Béthune
** Last update Sun Nov  1 18:00:06 2015 Julien Pignolet
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

char	*infin_mod(char *nb1, char *nb2)
{
  char	*mod;
  char	*res_mult;
  char	*res_div;

  res_div = infin_div(nb1, nb2);
  res_mult = infin_mult(res_div, nb2);
  if (nb1[0] == '-' || nb2[0] == '-')
    mod = infin_sous(nb1, res_mult, my_strlen(nb1), my_strlen(res_mult), 1);
  else
    mod = infin_sous(nb1, res_mult, my_strlen(nb1), my_strlen(res_mult), 0);
  return (mod);
}
