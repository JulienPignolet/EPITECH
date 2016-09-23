#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/calc.h"
#include "./include/bistromathique.h"

int	try_null(char *nb)
{
  int	i;

  i = 0;
  while (nb[i] != '\0')
    {
      if (nb[i] != '0')
	return (0);
      i++;
    }
  return (1);
}

char	*my_remove000(char *str)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(*res) * my_strlen(str) + 1);
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

char	*my_removeminus(char *nb)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(*res) * (my_strlen(nb) + 1));
  if (nb[i] == '-')
    i++;
  while (nb[i] != '\0')
    {
      res[j] = nb[i];
      i++;
      j++;
    }
  return (res);
}

int	my_strcmp_div(char *s1, char *s2)
{
  int   i;

  i = 0;

  if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
    i++;
  if (s1[i] > s2[i])
    return (s1[i] - s2[i]);
  else if (s1[i] < s2[i])
    return (s1[i] - s2[i]);
  return (0);
}

char	*my_div_sous(char *nb)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(*res) * (my_strlen(nb) + 2));
  res[i] = '-';
  i++;
  while (nb[j] != '\0')
    {
      res[i] = nb[j];
      i++;
      j++;
    }
  return (res);
}
