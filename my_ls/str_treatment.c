/*
** str_treatment.c for str_treatment in /home/pignol_j/rendu/tests/my_ls
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Fri Nov 20 21:01:28 2015 Julien Pignolet
** Last update Fri Nov 27 11:21:55 2015 Julien Pignolet
*/

#include "ls.h"

int	my_strcmp(char *s1, char *s2)
{
  char	*str1;
  char	*str2;
  int	i;
  int	j;

  str1 = my_strdup(s1);
  str2 = my_strdup(s2);
  i = 0;
  j = 0;
  if (str1[0] == '.' && (str1[1] != '.' || str1[1] != '\n'))
    i++;
  if (str2[0] == '.' && (str2[1] != '.' || str2[1] != '\n'))
    j++;
  while (str1[i] != '\0' || str2[j] != '\0')
    {
      if (str1[i] >= 'A' && str1[i] <= 'Z')
	str1[i] = str1[i] + 32;
      if (str2[j] >= 'A' && str2[j] <= 'Z')
	str2[j] = str2[j] + 32;
      ((str1[i] - str2[j] == 0) ? (i++, j++) : (0));
      if (str1[i] - str2[j] != 0)
	return (str1[i] - str2[j]);
    }
  return (0);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  dest = malloc(my_strlen(src) + 1);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[my_strlen(src)] = 0;
  return (dest);
}

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) *
		    (my_strlen(s1) + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  while (s1[i] != '\0')
    {
      res[j] = s1[i];
      i++;
      j++;
    }
  i = 0;
  while (s2[i] != '\0')
    {
      res[j] = s2[i];
      i++;
      j++;
    }
  res[j] = '\0';
  return (res);
}
