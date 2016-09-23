/*
** ls.h for my_ls in /home/pignol_j/rendu/tests/my_ls
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Fri Nov 20 18:27:14 2015 Julien Pignolet
** Last update Sun Nov 29 15:55:13 2015 Julien Pignolet
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"

#define STRDUP (s1 = my_strdup(list->name), s2 = my_strdup(tmp->name))
#define R_RUSR (((check.st_mode & S_IRUSR) ? (new_elem->r_owner = 'r') : \
		 (new_elem->r_owner = '-')))
#define R_WUSR (((check.st_mode & S_IWUSR) ? (new_elem->w_owner = 'w') : \
		 (new_elem->w_owner = '-')))
#define R_XUSR (((check.st_mode & S_IXUSR) ? (new_elem->x_owner = 'x') : \
		 (new_elem->x_owner = '-')))
#define R_RGRP (((check.st_mode & S_IRGRP) ? (new_elem->r_group = 'r') : \
		 (new_elem->r_group = '-')))
#define R_WGRP (((check.st_mode & S_IWGRP) ? (new_elem->w_group = 'w') : \
		 (new_elem->w_group = '-')))
#define R_XGRP (((check.st_mode & S_IXGRP) ? (new_elem->x_group = 'x') : \
		 (new_elem->x_group = '-')))
#define R_ROTH (((check.st_mode & S_IROTH) ? (new_elem->r_other = 'r') : \
		 (new_elem->r_other = '-')))
#define R_WOTH (((check.st_mode & S_IWOTH) ? (new_elem->w_other = 'w') : \
		 (new_elem->w_other = '-')))
#define R_XOTH (((check.st_mode & S_IXOTH) ? (new_elem->x_other = 'x') : \
		 (new_elem->x_other = '-')))

struct s_list
{
  char		type;
  char		r_owner;
  char		w_owner;
  char		x_owner;
  char		r_group;
  char		w_group;
  char		x_group;
  char		r_other;
  char		w_other;
  char		x_other;
  char		*name;
  char		*username;
  char		*groupname;
  int		size;
  int		nlink;
  char		*day;
  struct s_list	*next;
};

struct s_option
{
  int	o_l;
  int	o_a;
  int	o_d;
};

struct s_name
{
  char		*name;
  struct s_name	*next;
};

typedef struct s_list t_list;
typedef struct s_option t_option;
typedef struct s_name t_name;
typedef struct dirent t_dirent;
typedef struct stat t_stat;

void	sort_ascii_list(t_list *);
void	swap_elem_list(t_list *, t_list *);
void	swap_elem_list2(t_list *, t_list *);
void	swap_elem_list3(t_list *, t_list *);
void	my_show_list(t_list *, t_option *, char *);
void	init_option(t_option *);
void	check_option(char *, t_option *);
int	my_put_in_list(t_list **, t_dirent *, char *, t_option *);
int	my_put_in_list2(t_stat, t_list *, t_option *);
int	my_put_in_name(t_name **, char *);
int	my_free_list(t_list **);
int	my_strcmp(char *, char *);
int	my_strlen(char *);
int	my_name_size(t_name *);
int	my_ls1(t_dirent *, t_list *, t_option *);
int	my_ls2(t_dirent *, t_list *, t_option *, t_name *);
char	*my_strdup(char *);
char	*my_time(char *);
char	*my_strcat(char *, char*);

#endif //MY_LS_H_
