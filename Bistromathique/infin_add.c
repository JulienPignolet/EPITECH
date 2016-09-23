/*
** infinadd.c for infinadd in /home/pignol_j/rendu/Piscine_C_infinadd
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Mon Oct 19 11:13:52 2015 julien pignolet
** Last update Sun Nov  1 20:10:57 2015 Julien Pignolet
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

char	*remove00(char *str, int sign)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(*res) * (my_strlen(str) + 1));
  if (sign == 1)
    {
      res[j] = '-';
      j++;
    }
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

char	*infin_sous(char *nb1, char *nb2, int j, int k, int sign)
{
  char	*res;
  int	i;
  int	ret;
  int	tamp;

  i = (my_complen(nb1, nb2) + 1);
  res = malloc(sizeof(*res) * (my_complen(nb1, nb2) + 1));
  res = my_memset(res, my_complen(nb1, nb2) + 1);
  ret = 0;
  while (i-- > 0)
    {
      if (nb1[j - 1] < 48 || nb1[j - 1] > 57 || j <= 0)
        nb1[j - 1] = '0';
      if (nb2[k - 1] < 48 || nb2[k - 1] > 57 || k <= 0)
        nb2[k - 1] = '0';
      tamp = (nb1[j - 1] - 48) - (nb2[k - 1] - 48) - ret;
      ret = 0;
      tamp < 0 ? ret = 1 : 0;
      tamp < 0 ? (res[i] += (tamp + 10)) : (res[i] += tamp);
      res[i] < 48 || res[i] > 57 ? (res[i] = '0') : 0;
      res[i] < 48 || res[i] > 57 ? (res[i - 1] = '0') : 0;
      j--;
      k--;
    }
  return (remove00(res, sign));
}

char	*infin_add(char *nb1, char *nb2, int j, int k, int sign)
{
  char	*res;
  int	i;
  int	tamp;

  i = (my_complen(nb1, nb2) + 1);
  res = malloc(sizeof(*res) * (my_complen(nb1, nb2) + 2));
  res = my_memset(res, my_complen(nb1, nb2) + 1);
  while (i-- > 0)
    {
      if (nb1[j - 1] < 48 || nb1[j - 1] > 57 || j <= 0)
	nb1[j - 1] = '0';
      if (nb2[k - 1] < 48 || nb2[k - 1] > 57 || k <= 0)
	nb2[k - 1] = '0';
      tamp = (nb1[j - 1] - 48) + (nb2[k - 1] - 48);
      res[i - 1] += tamp / 10;
      res[i] += tamp % 10;
      if (res[i] < 48 || res[i] > 57)
	{
	  res[i] = '0';
	  res[i - 1] = '1';
	}
      j--;
      k--;
    }
  return (remove00(res, sign));
}

char	*main_add_inf2(char *argv1, char *argv2, int j, int k)
{
  int	l;
  int	sign;

  sign = 0;
  if (my_try_fonction(argv1, argv2) == 0)
    {
    }
  else if (my_try_fonction(argv1, argv2) == 1)
    sign = 1;
  else if (my_try_fonction(argv1, argv2) == 2)
    {
      if (argv2[0] == '-' && my_strcmp_inf(argv2, argv1) > 0)
	(sign = 1);
      l = j;
      j = k;
      k = l;
      return (infin_sous(argv2, argv1, j, k, sign));
    }
  else if (my_try_fonction(argv1, argv2) == 3)
    {
      if (argv1[0] == '-' && my_strcmp_inf(argv1, argv2) > 0)
	(sign = 1);
      return (infin_sous(argv1, argv2, j, k, sign));
    }
  return (infin_add(argv1, argv2, j, k, sign));
}

char	*main_add_inf(char *nb1, char *nb2, int i, int j)
{
  char	*s1;
  char	*s2;
  s1 = malloc(sizeof(*s1) * (my_strlen(nb1) + 1));
  s2 = malloc(sizeof(*s2) * (my_strlen(nb2) + 1));
  while (nb1[i] == '0' && nb1[i + 1] != '\0')
    i++;
  while (nb1[i] != '\0')
    {
      s1[j] = nb1[i];
      i++;
      j++;
    }
  i = 0;
  j = 0;
  while (nb2[i] == '0' && nb2[i + 1] != '\0')
    i++;
  while (nb2[i] != '\0')
    {
      s2[j] = nb2[i];
      i++;
      j++;
    }
  return (main_add_inf2(s1, s2, my_strlen(s1), my_strlen(s2)));
}
