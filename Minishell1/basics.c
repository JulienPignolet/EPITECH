/*
** basics.c for minishell in /home/pignol_j/rendu/test/minishell1
**
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
**
** Started on  Sat Jan 23 16:06:54 2016 Julien Pignolet
** Last update Thu Feb 11 09:28:48 2016 Pignolet Julien
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str += 1;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
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
