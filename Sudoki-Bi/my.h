/*
** my.h for sudoku in /home/pignol_j/Rendu/Test/sudoku
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Sat Feb 27 17:28:47 2016 Pignolet Julien
** Last update Sun Feb 28 18:37:56 2016 Pignolet Julien
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define INIT (i = 1, j = 2)
#define INIT2 ((first != 0) ? (printf("####################\n")) : (0), \
	       i = 0, list = NULL, buf[size - 1] = '\0', tab = str_tab(buf))
#define FREE (memset(buf, 0, sizeof(char)), free(list), first = 1)
#define CHECK ((j > 18) ? (j = 2, ++i) : (0), \
	       (check_in(list, j, i) == 1) ? ((j == 18) ? \
					      (j = 2, ++i) : (j += 2)) : (0))
#define CHECK2 (check_col(tab, j, i, tab[i][j]) == 1 || \
		check_line(tab, i, j, tab[i][j]) == 1 || \
		  check_case(tab, j, i, tab[i][j]) == 1)
#define SET_POS ((y >= 1 && y <= 3 && x >= 2 && x <= 6) ? (x2 = 2, y2 = 1) : \
		 ((y >= 1 && y <= 3 && x >= 8 && x <= 12) ? (x2 = 8, y2 = 1) : \
		  ((y >= 1 && y <= 3 && x >= 14 && x <= 18) ? (x2 = 14, y2 = 1) : \
		   ((y >= 4 && y <= 6 && x >= 2 && x <= 6) ? (x2 = 2, y2 = 4) : \
		    ((y >= 4 && y <= 6 && x >= 8 && x <= 12) ? (x2 = 8, y2 = 4) : \
		     ((y >= 4 && y <= 6 && x >= 14 && x <= 18) ? (x2 = 14, y2 = 4) : \
		      ((y >= 7 && y <= 9 && x >= 2 && x <= 6) ? (x2 = 2, y2 = 7) : \
		       ((y >= 7 && y <= 9 && x >= 8 && x <= 12) ? (x2 = 8, y2 = 7) : \
			((y >= 7 && y <= 9 && x >= 14 && x <= 18) ? (x2 = 14, y2 = 7) : \
			 (0))))))))))

struct s_list
{
  int		x;
  int		y;
  struct s_list	*next;
};
typedef struct s_list	t_list;

typedef struct s_fakochere
{
  int	i1;
  int	i2;
  int	i3;
  int	i4;
  int	i5;
  int	i6;
  int	i7;
  int	i8;
  int	i9;
} t_fako;

void	show_tab(char **);
void	aff_err();
char	**str_tab(char *);
int	check_error(char **);
int	my_put_in_list(t_list **, int, int);
int	check_in(t_list *, int, int);
int	check_error(char **);
int	check_line(char **, int, int, char);
int	check_col(char **, int, int, char);
int	check_case(char **, int, int, char);
int	check(int, int, char **, int);
int	check_solve(char **);
int	count_double_lin(char **, int);
int	count_double_col(char **, int);
int	check_no(char **);
int	my_ai(char **, t_list *);

#endif /* !MY_H_ */
