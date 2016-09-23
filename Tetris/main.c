/*
** main.c for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:21:26 2016 Pignolet Julien
** Last update Sun Mar 20 21:15:15 2016 Pignolet Julien
*/

#include "tetris.h"

float timedifference_msec(struct timeval t0, struct timeval t1)
{
  return ((t1.tv_sec - t0.tv_sec)
	  * 1000.0 + (t1.tv_usec - t0.tv_usec) / 1000.0);
}

int	my_game2(t_piece current, char **board, t_game *game, t_option option)
{
  t_pos		pos;
  t_pos		old_pos;
  t_piece	next;
  t_score	score;
  t_variable	var;

  INIT_GAME;
  while (1) {
      INIT_GAME2;
      if (pos.x1 == -1)
	return (score.score);
      INIT_GAME3;
      while (var.same == 1) {
	  SET_GAME;
	  if (QG)
	    return (score.score);
	  if (COLS < 45 + option.map_col || LINES < option.map_row || LINES < 22)
	    return (-1);
	  KEY_REP;
	  GT;
      if (PG)
	while ((option.kp != '\0') ? (getch() != option.kp) : (getch() != ' '));
      GAME;
	} END_GAME;
    }
}

int	my_game(t_game *game, t_option option)
{
  char		**board;
  t_piece	current;
  int		score;

  current = gen_next(game);
  board = my_board(option.map_row, option.map_col);
  score = my_game2(current, board, game, option);
  if (score > read_hscore())
    write_hscore(score);
  return (score);
}

int	main(int argc, char **argv)
{
  char		buf[1];
  t_game	*game;
  t_option	option;
  int		ret;

  game = NULL;
  tetriminos(&game);
  option = init_option();
  option = set_option(argv, option);
  srand(time(NULL));
  if (option.h == 1)
    my_help();
  else if (option.map_row <= 2 || option.map_col <= 4)
    my_putstr("Les dimensions minimum de la map sont : 2, 4\n");
  else
    SET_CURSES;
  if (ret == -1)
    printf("Les dimensions du terminal sont insuffisantes\n");
  return (0);
}
