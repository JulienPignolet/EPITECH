/*
** infinadd.c for infinadd in /home/pignol_j/rendu/Piscine_C_infinadd
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Mon Oct 19 11:13:52 2015 julien pignolet
** Last update Tue Oct 20 22:30:37 2015 julien pignolet
*/

#include <stdlib.h>
#include "./include/my.h"

char	*my_infin_add(char *str, int i)
{
  int	j;
  int	k;
  char	*res;

  j = 0;
  k = 0;
  res = malloc(sizeof(*res) * my_strlen(str) + 1);
  while (str[i] == '0')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
	i++;
      else
	{
	  res[j] = str[i];
	  j++;
	  i++;
	  k = 1;
	}
    }
  if (k == 0)
    res[0] = '0';
  return (res);
}

char	*infin_sous(char *nb1, char *nb2, int j, int k)
{
  char	*res;
  int	i;
  int	ret;
  int	tamp;

  i = (my_complen(nb1, nb2) + 1);
  res = malloc(sizeof(*res) * (my_complen(nb1, nb2) + 1));
  res = my_memset(res, my_complen(nb1, nb2) + 1);
  ret = 0;
  while (i-- > 0)
    {
      if (nb1[j - 1] < 48 || nb1[j - 1] > 57 || j <= 0)
        nb1[j - 1] = '0';
      if (nb2[k - 1] < 48 || nb2[k - 1] > 57 || k <= 0)
        nb2[k - 1] = '0';
      tamp = (nb1[j - 1] - 48) - (nb2[k - 1] - 48) - ret;
      ret = 0;
      tamp < 0 ? ret = 1 : 0;
      tamp < 0 ? (res[i] += (tamp + 10)) : (res[i] += tamp);
      res[i] < 48 || res[i] > 57 ? (res[i] = '0') : 0;
      res[i] < 48 || res[i] > 57 ? (res[i - 1] = '0') : 0;
      j--;
      k--;
    }
  return (my_infin_add(res, 0));
}

char	*infin_add(char *nb1, char *nb2, int j, int k)
{
  char	*res;
  int	i;
  int	tamp;

  i = (my_complen(nb1, nb2) + 1);
  res = malloc(sizeof(*res) * (my_complen(nb1, nb2) + 2));
  res = my_memset(res, my_complen(nb1, nb2) + 1);
  while (i-- > 0)
    {
      if (nb1[j - 1] < 48 || nb1[j - 1] > 57 || j <= 0)
	nb1[j - 1] = '0';
      if (nb2[k - 1] < 48 || nb2[k - 1] > 57 || k <= 0)
	nb2[k - 1] = '0';
      tamp = (nb1[j - 1] - 48) + (nb2[k - 1] - 48);
      res[i - 1] += tamp / 10;
      res[i] += tamp % 10;
      if (res[i] < 48 || res[i] > 57)
	{
	  res[i] = '0';
	  res[i - 1] = '1';
	}
      j--;
      k--;
    }
  return (my_infin_add(res, 0));
}

int	main_add_inf(char *argv1, char *argv2, int j, int k)
{
  int	l;

  j = my_strlen(argv1);
  k = my_strlen(argv2);
  if (my_try_fonction(argv1, argv2) == 0)
    {
    }
  else if (my_try_fonction(argv1, argv2) == 1)
    my_putchar('-');
  else if (my_try_fonction(argv1, argv2) == 2)
    {
      if (argv2[0] == '-' && my_strcmp_inf(argv2, argv1) > 0)
	my_putchar('-');
      l = j;
      j = k;
      k = l;
      return (my_putstr_inf(infin_sous(argv2, argv1, j, k)));
    }
  else if (my_try_fonction(argv1, argv2) == 3)
    {
      if (argv1[0] == '-' && my_strcmp_inf(argv1, argv2) > 0)
	my_putchar('-');
      return (my_putstr_inf(infin_sous(argv1, argv2, j, k)));
    }
    return (my_putstr_inf(infin_add(argv1, argv2, j, k)));
}

int	main(int argc, char **argv)
{
  int	j;
  int	k;

  if (argc != 3)
    return (my_putstr_inf("Usage : ./infin_add nombre1 nombre2"));
  else
    main_add_inf(argv[1], argv[2], j, k);
}
