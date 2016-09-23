/*
** bsq.h for BSQ in /home/pignol_j/rendu/tests/BSQ
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Mon Dec 14 12:44:51 2015 Julien Pignolet
** Last update Fri Dec 18 16:19:09 2015 Julien Pignolet
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define INIT_STR_TO_WORDTAB (i = 0, j = 0, k = 0)
#define SET_SAVE (save->x = x, save->y = y, \
		  save->pos_x = pos->x, save->pos_y = pos->y)
#define INIT_BSQ (x = 0, y = 0, pos->x = j, pos->y = i)
#define INCR_BSQ (++x, ++y)
#define DEINCR_BSQ (++i, j = 0)
#define SET_VAR (i = 1,  j = 0)

struct s_pos
{
  int	x;
  int	y;
};

struct s_save
{
  int	x;
  int	y;
  int	pos_x;
  int	pos_y;
};

typedef struct stat	t_stat;
typedef struct s_pos	t_pos;
typedef struct s_save	t_save;

void	my_putchar(char);
void	my_putstr(char *);
void	my_show_tab(char **);
void	init_struct(t_pos *, t_save *);
char	**my_str_to_wordtab(char *);
char	**my_file_to_tab(char *);
char	**bsq(char **, char *);
char	**write_bsq(char **, t_save *);
char	**tab_1_x(char **, int *, int *, int *);
int	check_bsq(char **, t_pos *, int, int, int, int);
int	count_l(char *);
int	count_c(char *, int);
int	my_strlen(char *);

#endif /* !BSQ_H_ */
