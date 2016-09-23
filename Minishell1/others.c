
/*
** others.c for minishell in /home/pignol_j/rendu/test/sh1
**
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
**
** Started on  Sun Jan 24 20:50:46 2016 Julien Pignolet
** Last update Sat Jan 30 20:01:39 2016 Julien Pignolet
*/

#include "my.h"

int	match(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '=')
    {
      if (s2[i] != s1[i])
	return (0);
      ++i;
    }
  return (1);
}

int	check_builtins(char *str)
{
  if (str[0] == 'e' && str[1] == 'n' && str[2] == 'v')
    return (1);
  if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't')
    return (2);
  if (str[0] == 'c' && str[1] == 'd')
    return (3);
  if (str[0] == 's' && str[1] == 'e' && str[2] == 't' &&
      str[3] == 'e' && str[4] == 'n' && str[5] == 'v')
    return (4);
  if (str[0] == 'u' && str[1] == 'n' && str[2] == 's' && str[3] == 'e' &&
      str[4] == 't' && str[5] == 'e' && str[6] == 'n' && str[7] == 'v')
    return (5);
  return (0);
}

char	*get_path(char **env, char *com)
{
  int	i;
  char	**tab;

  i = 0;

  if (env == NULL)
    return (com);
  while (env[i][0] != 'P' || env[i][1] != 'A' ||
	 env[i][2] != 'T' || env[i][3] != 'H')
    {
      ++i;
      if (env[i] == NULL)
	return (com);
    }
  tab = str_tab_path(env[i]);
  i = 0;
  while (tab[i] != NULL)
    {
      if (access(my_strcat(my_strcat(tab[i], "/"), com), 0) != -1)
	return (my_strcat(my_strcat(tab[i], "/"), com));
      ++i;
    }
  return (com);
}

char	*get_oldpwd(char **env)
{
  int	i;
  char	**tab;

  i = 0;
  while (env[i][0] != 'O' || env[i][1] != 'L' || env[i][2] != 'D'
	 || env[i][3] != 'P' || env[i][4] != 'W' || env[i][5] != 'D')
    ++i;
  tab = str_tab_path2(env[i]);
  return (tab[0]);
}

int	check_number(char *str)
{
  int	i;
  int	letter;
  int	number;

  i = 0;
  letter = 0;
  number = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	letter = 1;
      else
	number = 1;
      ++i;
    }
  if (letter == 1 && number == 1)
    return (2);
  else if (letter == 1)
    return (1);
  else
    return (0);
}
