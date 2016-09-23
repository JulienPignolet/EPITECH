/*
** load_array.c for BSQ in /home/pignol_j/rendu/CPE_2015_BSQ
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Tue Dec 15 15:39:31 2015 Julien Pignolet
** Last update Tue Dec 15 22:29:05 2015 Julien Pignolet
*/

#include "bsq.h"

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  INIT_STR_TO_WORDTAB;
  if ((tab = malloc(sizeof(char *) * (count_l(str) + 2))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if ((tab[j] = malloc(sizeof(char) * count_c(str, j) + 1)) == NULL)
	return (NULL);
      while (str[i] != '\n' && str[i] != '\0')
	{
	  tab[j][k] = str[i];
	  ++k;
	  ++i;
	}
      tab[j][k] = '\0';
      ++j;
      k = 0;
      ((str[i] != '\0') ? (++i) : (0));
    }
  tab[j] = NULL;
  return (tab);
}

char	**my_file_to_tab(char *filepath)
{
  int		fd;
  int		ret;
  t_stat	size;
  char		*buffer;

  if ((stat(filepath, &size)) == -1)
    return (NULL);
  if ((buffer = malloc(sizeof(char) * size.st_size + 1)) == NULL)
    return (NULL);
  buffer[size.st_size] = '\0';
  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (NULL);
  if ((ret = read(fd, buffer, size.st_size)) == -1)
    return (NULL);
  return (bsq(my_str_to_wordtab(buffer), buffer));
}

void	my_show_tab(char **tab)
{
  int	i;

  i = 1;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      ++i;
    }
}

int	count_l(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	++count;
      ++i;
    }
  return (count);
}

int	count_c(char *str, int l)
{
  int	i;
  int	count_l;
  int	count_c;

  i = 0;
  count_l = 0;
  count_c = 0;
  while (count_l != l && str[i] != '\0')
    {
      if (str[i] == '\n')
	++count_l;
      ++i;
    }
  if (count_l == l)
    {
      while (str[i] != '\n' && str[i] != '\0')
	{
	  ++i;
	  ++count_c;
	}
    }
  return (count_c);
}
