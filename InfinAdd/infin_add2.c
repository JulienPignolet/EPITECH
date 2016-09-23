/*
** infin_add2.c for infin_add2 in /home/pignol_j/Test ladinf
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Tue Oct 20 20:42:04 2015 julien pignolet
** Last update Tue Oct 20 20:44:47 2015 julien pignolet
*/

char    *my_memset(char *res, int size)
{
  int   i;

  i = 0;
  while (i < size)
    {
      res[i] = '0';
      i++;
    }
  return (res);
}

int     my_strcmp_inf(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (my_strlen(s1) - 1 < my_strlen(s2))
    return (-1);
  if (my_strlen(s1) - 1 > my_strlen(s2))
    return (1);
  while (s1[i + 1] == s2[i] && s1[i + 1] != 0 && s2[i] != 0)
    i++;
  if (s1[i + 1] > s2[i])
    return (s1[i + 1] - s2[i]);
  else if (s1[i + 1] < s2[i])
    return (s1[i + 1] - s2[i]);
  return (0);
}

int     my_complen(char *nb1, char *nb2)
{
  int   l1;
  int   l2;

  l1 = my_strlen(nb1);
  l2 = my_strlen(nb2);
  if (l1 > l2)
    return (l1);
  else
    return (l2);
}

int     my_putstr_inf(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  my_putchar('\n');
  return (0);
}

int     my_try_fonction(char *ar1, char *ar2)
{
  if (ar1[0] == '-' && ar2[0] == '-'
      && (ar1[1] == '0' && ar2[1] == '0')
      && (ar1[2] == '\0' && ar2[2] == '\0'))
    return (0);
  else if (ar1[0] == '-' && ar2[0] == '-')
    return (1);
  else if (ar1[0] == '-' && my_strcmp_inf(ar1, ar2) <= 0
           || (ar2[0] == '-' && my_strcmp_inf(ar2, ar1) >= 0))
    return (2);
  else if (ar2[0] == '-' && my_strcmp_inf(ar2, ar1) <= 0
           || (ar1[0] == '-' && my_strcmp_inf(ar1, ar2) >= 0))
    return (3);
}
