/*
** basics2.c for allum1 in /home/pignol_j/Rendu/CPE_2015_Allum1
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Fri Feb 12 19:46:39 2016 Pignolet Julien
** Last update Sun Feb 21 01:07:51 2016 Pignolet Julien
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
  while (dest[i] != '\0')
    {
      res[i] = dest[i];
      ++i;
    }
  while (src[j] != '\0')
    {
       res[i] = src[j];
      ++j;
      ++i;
    }
  res[i] = '\0';
  return (res);
}

int	my_getnbr(char *nb)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  if (nb[0] == '\0')
    return (-1);
  while (nb[i])
    {
      if (nb[i] >= '0' && nb[i] <= '9')
        {
          res *= 10;
          res += nb[i] - '0';
        }
      else
	return (-1);
      ++i;
    }
  return (res);
}
