/*
** option.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sun Mar 20 14:19:48 2016 Pignolet Julien
*/

#include "tetris.h"

int	get_level(char *str)
{
  int	i;
  int	j;
  char	*nb;

  nb = malloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  j = 0;
  while (str[i] != '=' && str[i])
    ++i;
  if (str[i])
    ++i;
  if (str[i])
    while (str[i])
      {
	nb[j] = str[i];
	++i;
	++j;
      }
  nb[j] = '\0';
  return (my_atoi(nb));
}

void	get_map(int *row, int *col, char *str)
{
  int	i;
  int	j;
  char	*nb;

  GM1;
  while (str[i] != '=' && str[i])
    ++i;
  if (str[i])
    {
      ++i;
      while (str[i] != ',' && str[i])
	GM2;
    }
  nb[j] = '\0';
  j = 0;
  *row = my_atoi(nb);
  nb = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (str[i])
    {
    ++i;
    while (str[i])
      GM3;
    }
  nb[j] = '\0';
  *col = my_atoi(nb);
}

char	get_key(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '=' && str[i])
    ++i;
  if (str[i] && str[i + 1])
    return (str[i + 1]);
  return ('\0');
}

t_option	init_option()
{
  t_option	option;

  option.h = 0;
  option.l = 1;
  option.kl = '\0';
  option.kr = '\0';
  option.kt = '\0';
  option.kd = '\0';
  option.kq = '\0';
  option.kp = '\0';
  option.map_row = 20;
  option.map_col = 10;
  option.w = 0;
  option.d = 0;
  return (option);
}

t_option	set_option(char **board, t_option option)
{
  int		i;

  i = 0;
  while (board[i] != NULL)
    SET_OPTION;
  return (option);
}
