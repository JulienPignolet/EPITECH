/*
** infin_div.c for infin_div in /home/pignol_j/rendu/Piscine_C_infindiv
** 
** Made by Julien PIGNOLET
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct 29 12:22:00 2015 Julien PIGNOLET
** Last update Sun Nov  1 20:09:43 2015 Julien Pignolet
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

char	*my_nbr_to_str(int nb)
{
  int	nb_tamp;
  int	i;
  int	div;
  char	*res;

  i = 0;
  div = 1;
  nb_tamp = 0;
  res = malloc(sizeof(*res) * nb);
  while ((nb / div) >= 10)
    div *= 10;
  while (div > 0)
    {
      nb_tamp = (nb /div) % 10;
      res[i] = nb_tamp + 48;
      i++;
      div /= 10;
    }
  return (res);
}

char	*my_add_to_str(char *s1, char *s2, int j)
{
  int	i;
  char	*res;

  res = malloc(sizeof(*res) * (my_strlen(s1) + my_strlen(s2) + 1));
  res = my_strcpy(res, s1);
  i = my_strlen(res);
  while (s2[j] != '\0')
    {

      res[i] = s2[j];
      i++;
      j++;
    }
  return (res);
}

char	*my_add_to_str2(char *s1, char *s2)
{
  char	*res;
  int	i;
  int	j;

  res = malloc(sizeof(*res) * (my_strlen(s1) + my_strlen(s2) + 1));
  res = my_strcpy(res, s1);
  i = my_strlen(res);
  j = 0;
  while (s2[j] != '\0')
    {
      res[i] = s2[j];
      j++;
      i++;
    }
  return (res);
}

char	*infin_div2(char *nb, char *div, int i, int t1)
{
  char	*res;
  char	*div_sous;
  char	*nb_tamp;
  int	j;
  int	count;

  nb_tamp = malloc(sizeof(*nb_tamp) * my_strlen(nb) + 1);
  while (nb [i] != '\0')
    {
      count = 0; j = my_strlen(nb_tamp);
      while ((my_strcmp_div(nb_tamp, div) <= 0 &&
	      my_strcmp_div(nb, div) > 0 && nb[i] != '\0') || (i == 0))
	{
	  nb_tamp[j] = nb[i]; j++; i++;
	  if (my_strcmp_div(nb_tamp, div) <= 0 && t1 != 1)
	    res = my_add_to_str2(res, "0");
	}
      nb_tamp = my_remove000(nb_tamp);
      while (my_strcmp_div(nb_tamp, div) >= 0 && try_null(nb_tamp) != 1)
	{
	  nb_tamp = main_add_inf(nb_tamp, my_div_sous(div), 0, 0); count++;
	}
      if (t1 == 1) { res = my_nbr_to_str(count); t1 = 0; }
      else { res = my_add_to_str2(res, my_nbr_to_str(count)); }
    } return (res);
}

char	*infin_div(char *nb, char *div)
{
  char	*res;

  if (div[0] == '0' && div[1] == '\0')
    return ("Division par 0 !");
  if (my_strcmp_div(nb, div) < 0)
    return ("0");
  if (my_strcmp(nb, div) == 0)
    return ("1");
  else
    {
      if (nb[0] == '-' && div[0] != '-' || nb[0] != '-' && div[0] == '-')
	{
	  nb = my_removeminus(nb);
	  div = my_removeminus(div);
	  res = my_add_to_str2("-", infin_div2(nb, div, 0, 1));
	  return (res);
	}
      else
	{
	  nb = my_removeminus(nb);
	  div = my_removeminus(div);
	  return (infin_div2(nb, div, 0, 1));
	}
    }
}
