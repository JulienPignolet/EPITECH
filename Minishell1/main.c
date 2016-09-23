
/*
** main.c for minishell1 in /home/pignol_j/rendu/test/minishell1
**
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
**
** Started on  Thu Jan 21 16:49:11 2016 Julien Pignolet
** Last update Thu Feb 11 13:19:46 2016 Pignolet Julien
*/

#include "my.h"

char	*my_epure(char *str)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  res = malloc(sizeof(char) * my_strlen(str) + 1);
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i] != '\0')
    {
      res[j] = str[i];
      ++j;
      if (str[i] == ' ' || str[i] == '\t')
	while (str[i] == ' ' || str[i] == '\t')
	  ++i;
      else
	++i;
    }
  res[j] = '\0';
  return (res);
}

int	c_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (0);
      ++i;
    }
  return (1);
}

int	minishell(char **env)
{
  int	i;
  int	pid_stat;
  char	*buf;
  char	*tmp;
  char	*path;
  char	tmpr[1];
  char	**tab;
  pid_t	pid;

  while (1)
    {
      i = 1;
      tmpr[0] = '\0';
      my_putstr("$>");
      while (tmpr[0] != '\n')
	READ_IN;
      buf = my_epure(buf);
      tab = str_tab(buf);
      (check_builtins(buf) == 2) ?
	((my_exit(buf) == 0) ? ((tab[1] == NULL) ? (exit(0)) :
				(exit(my_atoi(tab[1])))) : (0)) :
	((c_space(buf) == 1) ? (0) : (path = get_path(env, tab[0]), BUILTINS_EXEC));
    }
}

int	main(int argc, char **argv, char **env)
{
  if (argc == 1)
    minishell(env);
  else
    my_putstr("Usage : ./minishell\n");
  return (0);
}
