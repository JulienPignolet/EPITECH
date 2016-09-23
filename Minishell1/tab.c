/*
** tab.c for minishell in /home/pignol_j/rendu/test/minishell1
**
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
**
** Started on  Sat Jan 23 16:03:37 2016 Julien Pignolet
** Last update Sun Jan 31 14:39:03 2016 Julien Pignolet
*/

#include "my.h"

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
	my_putstr(tab[i]);
	my_putchar('\n');
	++i;
      }
}

char	**str_tab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str[i] != '\0')
    {
      tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
      k = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
	  tab[j][k] = str[i];
	  ++i;
	  ++k;
	}
      (str[i] == ' ' || str[i] == '\t') ? (++i) : (0);
      tab[j][k] = '\0';
      ++j;
    }
  tab[j] = NULL;
  return (tab);
}

char	**str_tab_path(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 5;
  j = 0;
  tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str[i] != '\0')
    {
      tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
      k = 0;
      while (str[i] != ':' && str[i] != '\0')
	{
	  tab[j][k] = str[i];
	  ++i;
	  ++k;
	}
      (str[i] == ':') ? (++i) : (0);
      tab[j][k] = '\0';
      ++j;
    }
  tab[j] = NULL;
  return (tab);
}

char	**str_tab_path2(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 7;
  j = 0;
  tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str[i] != '\0')
    {
      tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
      k = 0;
      while (str[i] != ':' && str[i] != '\0')
	{
	  tab[j][k] = str[i];
	  ++i;
	  ++k;
	}
      (str[i] == ':') ? (++i) : (0);
      tab[j][k] = '\0';
      ++j;
    }
  tab[j] = NULL;
  return (tab);
}

int     my_atoi(char *str)
{
  int val;

  val = 0;
  while (*str)
    {
      if (*str >= '0' && *str <= '9')
        {
          val *= 10;
          val += *str - '0';
        }
      else
        return (val);
      str++;
    }
  return (val);
}
