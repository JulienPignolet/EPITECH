/*
** get_next_line.c for get_next_line in /home/pignol_j/rendu/CPE_2015_getnextline
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Wed Jan 13 20:18:33 2016 Julien Pignolet
** Last update Sun Jan 17 10:06:47 2016 Julien Pignolet
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#define MALLOC1 ((tmp_buf = malloc(sizeof(char) * (x * READ_SIZE))) == NULL)
#define MALLOC2 ((buf = malloc(sizeof(char) * (x * READ_SIZE + 1))) == NULL)
#define RAC1 ((x == 1) ? (my_memset(buf, 0, 1), \
			  my_memset(tmp, 0, READ_SIZE), i = 0) : (i = 0))
#define RAC2 (tmp_buf = my_memset(tmp_buf, 0, (x * READ_SIZE)), \
	      tmp_buf = my_strcpy(tmp_buf, buf), free(buf))
#define RAC3 (buf = my_memset(buf, 0, (x * READ_SIZE + 1)), \
	      buf = my_strcpy(buf, tmp_buf), buf = my_strcat(buf, tmp), \
	      my_memset(tmp, 0, READ_SIZE), free(tmp_buf), ++x)
#define RAC4 (res = my_memset(res, 0, (i + 1)), i = 0)
#define COPY (res[i] = buf[0], ++buf, ++i)

int	my_strlen(char *);
char	*my_strcpy(char *, char *);
char	*my_memset(char *, char, int);
char	*my_strcat(char *, char *);
char	*get_next_line(const int);

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
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

char    *my_memset(char *str, char c, int size)
{
  int   i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      ++i;
    }
  return (str);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (j < READ_SIZE)
    {
      dest[i] = src[j];
      ++i;
      ++j;
    }
  dest[i] = '\0';
  return (dest);
}

char	*get_next_line(const int fd)
{
  int		i;
  static int	x = 1;
  int		ret;
  char		tmp[READ_SIZE];
  char		*res;
  char		*tmp_buf;
  static char	*buf;
  if (x == 1 && ((buf = malloc(sizeof(char))) == NULL)){return (NULL);
  }RAC1;
  while ((ret = read(fd, tmp, READ_SIZE)) > 0){
    if (ret == -1)
      return (NULL);
    if (MALLOC1){return (NULL);
    }RAC2;
    if (MALLOC2){return (NULL);
    }RAC3;
  }
  while (buf[++i] != '\n' && buf[++i] != '\0'){}
  if ((res = malloc(sizeof(char) * (i + 1))) == NULL){return (NULL);
  }RAC4;
  while (buf[0] != '\n' && buf[0] != '\0'){COPY;
  }
  (buf[0] == '\n') ? (++buf) : (0);
  if (my_strlen(buf) == 0 && my_strlen(res) == 0){return (NULL);
  }return (res);
}
