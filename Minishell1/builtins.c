/*
** builtins.c for mnishell in /home/pignol_j/rendu/test/sh1
**
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
**
** Started on  Sun Jan 24 20:49:05 2016 Julien Pignolet
** Last update Sun Jan 31 14:31:07 2016 Julien Pignolet
*/

#include "my.h"

void	my_env(char *str, char **env)
{
  char	**tab;

  tab = str_tab(str);
  if (my_strlen(str) > 3)
    {
      my_putstr("env: ");
      my_putstr(tab[1]);
      my_putstr(": Aucun fichier ou dossier de ce type\n");
    }
  else
    show_tab(env);
}

int	my_exit(char *buf)
{
  char	**tab;

  tab = str_tab(buf);
  if (my_strlen(tab[0]) > 4)
    {
      my_putstr(tab[0]);
      my_putstr(": Command not found.\n");
    }
  else if (tab[1] == NULL)
    {
      my_putstr("exit\n");
      return (0);
    }
  else if (tab[2] != NULL || check_number(tab[1]) == 1)
    my_putstr("exit: Expression Syntax.\n");
  else if (check_number(tab[1]) == 2)
    my_putstr("exit: Badly formed number.\n");
  else
    {
      my_putstr("exit\n");
      return (0);
    }
  return (1);
}

char	**my_cd(char **tab, char **env)
{
  char	buf[5000];

  getcwd(buf, 5000);
  if (tab[1] == NULL)
    DEFAULT_CD;
  else
    if (tab[2] != NULL)
      my_putstr("cd : Too many arguments.\n");
    else if (tab[1][0] == '-' && tab[1][1] == '\0')
      CD_MINUS;
    else
      if (tab[1][0] == '/')
	(access(tab[1], 0) == -1) ?
	  (my_putstr(tab[1]),
	   my_putstr(": Aucun fichier ou dossier de ce type.\n")) :
	  (chdir(tab[1]), env = my_setenv(env, my_strcat("RUMBLE OLDPWD ", buf)),
	   env = my_setenv(env, my_strcat("RUMBLE PWD ", tab[1])));
      else
	(access(my_strcat(my_strcat(buf, "/"), tab[1]), 0) == -1) ?
	  (my_putstr(tab[1]), my_putstr(": Aucun fichier ou dossier de ce type.\n"))
	  : (chdir(my_strcat(my_strcat(buf, "/"), tab[1])), env = my_setenv
	     (env, my_strcat("RUMBLE OLDPWD ", buf)), env = my_setenv
	     (env, my_strcat("RUMBLE PWD ",
			     my_strcat(my_strcat(buf, "/"), tab[1]))));
  return (env);
}

char	**my_setenv(char **env, char *buf)
{
  int	i;
  char	**new_env;
  char	**tab;

  tab = str_tab(buf);
  i = 0;
  if (tab[1] != NULL) {
    if (tab[2] != NULL)
      if (tab[3] != NULL) {
	my_putstr("setenv : Too many arguments.\n");
	return (env);
      }
    while (env[i] != NULL)
      MATCH_SETENV;
    new_env = malloc(sizeof(char *) * (i + 2));
    i = 0;
    while (env[i] != NULL)
      COPY_ENV;
    (tab[2] == NULL) ? (new_env[i] = my_strcat(my_strcat(tab[1], "="), "\0"))
      : (new_env[i] = my_strcat(my_strcat(tab[1], "="), tab[2]));
    new_env[i + 1] = NULL;
    return (new_env);
  }
  my_env("env", env);
  return (env);
}

char	**my_unsetenv(char **env, char *buf, int k)
{
  int	i;
  int	j;
  char	**tab;
  char	**new_env;

  tab = str_tab(buf);
  i = 0;
  if (tab[k] != NULL)
    {
      if (tab[k][0] == '*' && tab[k][1] == '\0')
	return (NULL);
      while (env[i] != NULL)
	++i;
      new_env = malloc(sizeof(char *) * (i + 1));
      i = 0;
      j = 0;
      while (env[i] != NULL)
	(match(env[i], tab[k]) == 1) ? (++i) : (new_env[j] = env[i], ++i, ++j);
      new_env[j] = NULL;
      if (tab[k + 1] != NULL)
	return (my_unsetenv(new_env, buf, k + 1));
      return (new_env);
    }
  my_putstr("unsetenv: Too few arguments.\n");
  return (env);
}
