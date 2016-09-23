/*
** tetris.h for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:42:09 2016 Pignolet Julien
** Last update Sun Mar 20 17:40:56 2016 hakobi_a
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <term.h>
#include "cafe.h"

struct s_score
{
  int	min;
  int	sec;
  int	score;
  int	line;
  int	hscore;
  int	level;
  int	lr;
};
typedef struct s_score	t_score;

struct s_option
{
  int	h;
  int	l;
  char	kl;
  char	kr;
  char	kt;
  char	kd;
  char	kq;
  char	kp;
  int	map_row;
  int	map_col;
  int	w;
  int	d;
};
typedef struct s_option t_option;

struct s_piece
{
  char	name;
  int	L;
  int	l;
  int	color;
  int	turn;
  char	*piece;
};
typedef struct s_piece t_piece;

struct s_pos
{
  int	x1;
  int	y1;
  int	x2;
  int	y2;
  int	x3;
  int	y3;
  int	x4;
  int	y4;
};
typedef struct s_pos t_pos;

typedef struct s_game
{
  char		name;
  int		y;
  int		x;
  int		color;
  char		*piece;
  struct s_game	*next;
} t_game;

typedef struct s_high_score
{
  int score;
  struct s_high_score *next;
} t_high_score;

typedef struct s_variable
{
  time_t	temps_init;
  time_t	temps_fin;
  struct	timeval t0;
  struct	timeval t1;
  float		breake;
  int		timer;
  int		rep;
  int		same;
  int		clavier;
  int		z;
} t_variable;

void		my_putchar(char);
void		my_putstr(char *);
void		my_put_nbr(int);
void		my_show_tab(char **);
void		my_show_board(char **);
void		my_next(int, t_piece);
void		tetriminos(t_game **);
void		my_title();
void		my_help();
void		my_debug(t_option, t_game *);
void		my_high_score(t_score);
void		write_hscore(int);
void		get_map(int *, int *, char *);
int		my_strlen(char *);
int		my_atoi(char *);
int		check_border(char **, t_pos, t_pos);
int		add_list(t_game **, t_piece);
int		count_line(char **, t_pos, t_pos);
int		my_atoi_char(char);
int		check_lose(t_pos, char **);
int		read_hscore();
int		my_game2(t_piece, char **, t_game *, t_option);
int		my_game(t_game *, t_option);
int		match(char *, char *);
int		get_level(char *);
char		get_key(char *);
char		*int_to_char(int);
char		**set_pos(char **, t_pos, t_pos, t_piece);
char		**my_remove(char **, int);
char		**check_remove(char **, int *, int *);
char		**my_board(int, int);
t_pos		init_pos(t_piece, char **, int);
t_pos		check_border2(char **, t_pos, t_pos, int);
t_pos		down_pos(t_pos);
t_pos		turn_i(t_piece *, t_pos, t_pos, char **);
t_pos		turn_l(t_piece *, t_pos, t_pos, char **);
t_pos		turn_t(t_piece *, t_pos, t_pos, char **);
t_pos		turn_z(t_piece *, t_pos, t_pos, char **);
t_pos		turn(t_piece *, t_pos, t_pos, char **);
t_piece		gen_next(t_game *);
t_option	init_option();
t_option	set_option(char **, t_option);

#endif /* !TETRIS_H_ */
