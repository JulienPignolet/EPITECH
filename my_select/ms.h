/*
** ms.h for my_select in /home/pignol_j/rendu/PSU_2015_my_select
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Dec  3 10:59:30 2015 Julien Pignolet
** Last update Wed Dec  9 15:59:30 2015 Julien Pignolet
*/

#ifndef MS_H_
#define MS_H_

#define K_UP (((clavier == KEY_DOWN) ? (tamp = tamp->next, tamp->current = 1, \
				   tamp->prev->current = 0) : (0)))

#define K_DOWN (((clavier == KEY_UP) ? (tamp = tamp->prev, tamp->current = 1, \
			  tamp->next->current = 0) : (0)))

#define K_SPACE (((clavier == ' ') ? (((tamp->select == 1) ? \
			   (tamp->select = 0) : (tamp->select = 1)), \
			    tamp = tamp->next, tamp->current = 1, \
				     tamp->prev->current = 0) : (0)))

#define K_SUPPR (((clavier == KEY_BACKSPACE || clavier == KEY_DC) ? \
	       (tamp->current = 0, tamp->next->current = 1 , \
		  ((tamp->next == *list || \
		    tamp == *list) ? (tamp->next->c_x = 4, tamp->next->c_y = 2) : \
		   (tamp->next->c_x = tamp->c_x, tamp->next->c_y = tamp->c_y)), \
		tamp->prev->next = tamp->next, tamp->next->prev = tamp->prev, \
		((tamp == *list) ? (*list = (*list)->next) : (0)), \
		((tamp->prev == *list && tamp->next == *list && tamp == *list) ? \
		 (*stop = 1) : (0)), tamp = tamp->next) : (0)))

#define K_ENTRY (((clavier == '\n') ? (*stop = 2) : (0)))

#define TEXT (((tamp->select == 1) ? (attron(A_REVERSE), \
			      mvprintw(y, x + 4, tamp->name), attroff(A_REVERSE)) : \
       ((tamp->current == 1) ? (attron(A_UNDERLINE), \
				mvprintw(y, x + 4, tamp->name), attroff(A_UNDERLINE)) : \
	(mvprintw(y, x + 4, tamp->name)))))

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

struct s_list
{
  char		*name;
  int		c_x;
  int		c_y;
  int		select;
  int		current;
  struct s_list	*prev;
  struct s_list	*next;
};

typedef struct s_list t_list;

int	my_strlen(char *);
void	my_putchar(char);
void	my_putstr(char *);
void	my_putend_list(t_list**, char *);
void	my_show_list(t_list **, int *);
void	my_show_select(t_list **);
void	my_select2(t_list **, int *);
void	my_select(t_list **);

#endif //MS_H_
