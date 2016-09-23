/*
** my.h for allum1 in /home/pignol_j/Rendu/CPE_2015_Allum1
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Fri Feb 12 19:51:21 2016 Pignolet Julien
** Last update Sun Feb 21 00:57:48 2016 Pignolet Julien
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include "ai.h"

#define READ1 ((i > 1) ? (tmp = buf) : (0), buf = malloc(sizeof(char)	\
							 * (i + 1)), (i > 1) ? \
	       (buf = my_strcpy(buf, tmp), free(tmp)) :	\
	       (buf[0] = '\0'), read(0, tmpr, 1), tmpr[1] = '\0', \
	       (tmpr[0] != '\n') ? (buf = my_strcat(buf, tmpr)) : \
	       (line = get_line(buf)), ++i)

#define READ2 ((i > 1) ? (tmp = buf) : (0), buf = malloc(sizeof(char) \
							 * (i + 1)), (i > 1) ? \
	       (buf = my_strcpy(buf, tmp), free(tmp)) : \
	       (buf[0] = '\0'), read(0, tmpr, 1), tmpr[1] = '\0', \
	       (tmpr[0] != '\n') ? (buf = my_strcat(buf, tmpr)) : \
	       (match = get_match(buf)), ++i)

#define RMV (allum = set_allum(allum, match, line), \
	     my_putstr("Player removed "), my_put_nbr(match), \
	     my_putstr(" match(es) from line "), my_put_nbr(line), \
	     my_putchar('\n'), my_board(allum))

#define INIT (my_putstr("Your turn:\n"), line = -1, i = 1, match = -1)

#define INIT_BIS (line = -1, i = 1, match = -1)

#define INIT2 ((i != 1) ? (free(buf)) : (0), i = 1, \
	       tmpr[0] = '\0', my_putstr("Line: "))

#define INIT3 ((i != 1) ? (free(buf)) : (0), i = 1, \
	       tmpr[0] = '\0', my_putstr("Matches: "))

#define WIN ((xor == 0) ? (match = 1, ((allum.l1 != 0) ? \
				      (allum.l1 -= match, line = 1) :	\
				      ((allum.l2 != 0) ? (allum.l2 -= match, line = 2) : \
				       ((allum.l3 != 0) ? (allum.l3 -= match, line = 3) : \
					((allum.l4 != 0) ? (allum.l4 -= match, line = 4) : \
					 (0)))))) : (0))

struct	s_allum
{
  int	l1;
  int	l2;
  int	l3;
  int	l4;
};
typedef struct s_allum t_allum;

int	my_strlen(char *);
int	my_getnbr(char *);
int	check_end(t_allum, char *);
int	check_line(t_allum, int);
int	get_line(char *);
int	get_match(char *);
int	set_line(t_allum, int);
int	set_match(t_allum, int, int);
char	*my_strcpy(char *, char *);
char	*my_strcat(char *, char *);
void	my_putchar(char);
void	my_putchar_error(char);
void	my_putstr(char *);
void	my_putstr_error(char *);
void	my_put_nbr(int);
void	my_game(t_allum);
void	my_board(t_allum);
t_allum	my_calc(t_allum);
t_allum	my_hard_ai(t_allum);
t_allum	set_allum(t_allum, int, int);

#endif /* !MY_H_ */
