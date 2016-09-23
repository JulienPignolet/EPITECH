/*
** tetris.h for tetris in /home/pignol_j/Rendu/PSU/PSU_2015_tetris
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Mon Feb 22 09:42:09 2016 Pignolet Julien
** Last update Sun Mar 20 21:14:52 2016 Pignolet Julien
*/

#ifndef CAFE_H_
#define CAFE_H_

#define COUNT_LINE (board[i][j] >= '0' && board[i][j] <= '9' &&	\
		    (i != pos.y1 || j != pos.x1) && (i != pos.y2 || j != pos.x2) && \
		    (i != pos.y3 || j != pos.x3) && (i != pos.y4 || j != pos.x4) && \
		    (i != old_pos.y1 || j != old_pos.x1) && \
		    (i != old_pos.y2 || j != old_pos.x2) && \
		    (i != old_pos.y3 || j != old_pos.x3) && \
		    (i != old_pos.y4 || j != old_pos.x4))

#define INIT_POS ((piece.name == 'i') ? (pos.x1 = col / 2 - 1, \
					 pos.y1 = 1, pos.x2 = col / 2, \
					 pos.y2 = 1, pos.x3 = pos.x2 + 1, \
					 pos.y3 = 1, pos.x4 = pos.x2 + 2, pos.y4 = 1) : \
		  ((piece.name == 'l') ? \
		   (pos.x1 = col / 2 - 1, pos.y1 = 2, pos.x2 = col / 2, \
		    pos.y2 = 2, pos.x3 = pos.x2 + 1, pos.y3 = 2, \
		    pos.x4 = pos.x2 + 1, pos.y4 = 1) : ((piece.name == 'o') ? \
							(pos.x1 = col / 2, pos.y1 = 1, \
							 pos.x2 = pos.x1 + 1, \
							 pos.y2 = 1, pos.x3 = pos.x1, pos.y3 = 2, \
							 pos.x4 = pos.x1 + 1, pos.y4 = 2) : \
							((piece.name == 't') ? (pos.x1 = col / 2 - 1, \
										pos.y1 = 1, pos.x2 = col / 2, \
										pos.y2 = 1, \
										pos.x3 = pos.x2 + 1, pos.y3 = 1, \
										pos.x4 = pos.x2, \
										pos.y4 = 2) : ((piece.name == 'z') ? \
											       (pos.x1 = col / 2 - 1, \
												pos.y1 = 1, pos.x2 = col / 2, \
												pos.y2 = 1, pos.x3 = pos.x2, \
												pos.y3 = 2, \
												pos.x4 = pos.x2 + 1, \
												pos.y4 = 2) : (0))))), \
		  (check_lose(pos, board) == -1) ? (pos.x1 = -1) : (0))

#define SHOW ((board[i][j] >= '1' && board[i][j] <= '5') ? \
	      (attron(COLOR_PAIR(my_atoi_char(board[i][j]))), \
	       mvprintw(y, x, "*"), \
	       attroff(COLOR_PAIR(my_atoi_char(board[i][j])))) : \
	      (mvprintw(y, x, "%c", board[i][j])))

#define GM1 (nb = malloc(sizeof(char) * (my_strlen(str) + 1)), i = 0, j = 0)

#define GM2 (nb[j] = str[i], ++i, ++j)

#define GM3 (nb[j] = str[i], ++i, ++j)

#define TITLE (attron(COLOR_PAIR(1)), mvprintw(1, 1, "*"), \
	       mvprintw(1, 2, "*"), mvprintw(1, 3, "*"), \
	       mvprintw(2, 2, "*"), mvprintw(3, 2, "*"), \
	       mvprintw(4, 2, "*"), mvprintw(5, 2, "*"), \
	       attroff(COLOR_PAIR(1)), attron(COLOR_PAIR(2)), \
	       mvprintw(1, 5, "*"), mvprintw(1, 6, "*"), \
	       mvprintw(1, 7, "*"), mvprintw(2, 5, "*"), \
	       mvprintw(3, 5, "*"), mvprintw(3, 6, "*"), \
	       mvprintw(4, 5, "*"), mvprintw(5, 5, "*"), \
	       mvprintw(5, 6, "*"), mvprintw(5, 7, "*"), \
	       attroff(COLOR_PAIR(2)), attron(COLOR_PAIR(3)), \
	       mvprintw(1, 9, "*"), mvprintw(1, 10, "*"), \
	       mvprintw(1, 11, "*"), mvprintw(2, 10, "*"), \
	       mvprintw(3, 10, "*"), mvprintw(4, 10, "*"), \
	       mvprintw(5, 10, "*"), attroff(COLOR_PAIR(3)), \
	       attron(COLOR_PAIR(4)), mvprintw(1, 13, "*"), \
	       mvprintw(1, 14, "*"), mvprintw(1, 15, "*"), \
	       mvprintw(2, 15, "*"), mvprintw(2, 13, "*"), \
	       mvprintw(3, 13, "*"), mvprintw(3, 14, "*"), \
	       mvprintw(4, 13, "*"), mvprintw(4, 15, "*"), \
	       mvprintw(5, 15, "*"), mvprintw(5, 13, "*"), \
	       attroff(COLOR_PAIR(4)), attron(COLOR_PAIR(5)), \
	       mvprintw(1, 17, "*"), mvprintw(1, 18, "*"), \
	       mvprintw(1, 19, "*"), mvprintw(2, 18, "*"), \
	       mvprintw(3, 18, "*"), mvprintw(4, 18, "*"), \
	       mvprintw(5, 17, "*"), mvprintw(5, 18, "*"), \
	       mvprintw(5, 19, "*"), attroff(COLOR_PAIR(5)), \
	       attron(COLOR_PAIR(6)), mvprintw(1, 21, "*"), \
	       mvprintw(1, 22, "*"), mvprintw(1, 23, "*"), \
	       mvprintw(2, 21, "*"), mvprintw(3, 21, "*"), \
	       mvprintw(3, 22, "*"), mvprintw(3, 23, "*"), \
	       mvprintw(4, 23, "*"), mvprintw(5, 23, "*"), \
	       mvprintw(5, 22, "*"), mvprintw(5, 21, "*"), attroff(COLOR_PAIR(6)))

#define NEXT ((current.name == 'i') ? \
	      (attron(COLOR_PAIR(current.color)), \
	       mvprintw(2, (40 + col), "****"), \
	       attroff(COLOR_PAIR(current.color))) : \
	      ((current.name == 'l') ? \
	       (attron(COLOR_PAIR(current.color)), \
		mvprintw(2, (42 + col), "*"), \
		mvprintw(3, (40 + col), "***"), \
		attroff(COLOR_PAIR(current.color))) : \
	       ((current.name == 'o') ? \
		(attron(COLOR_PAIR(current.color)), \
		 mvprintw(2, (40 + col), "**"), \
		 mvprintw(3, (40 + col), "**"), \
		 attroff(COLOR_PAIR(current.color))) : \
		((current.name == 't') ? \
	       (attron(COLOR_PAIR(current.color)), \
		mvprintw(2, (40 + col), "***"), \
		mvprintw(3, (41 + col), "*"), \
		attroff(COLOR_PAIR(current.color))) : \
		 ((current.name == 'z') ? \
		  (attron(COLOR_PAIR(current.color)), \
		   mvprintw(2, (40 + col), "**"), \
		   mvprintw(3, (41 + col), "**"), \
		   attroff(COLOR_PAIR(current.color))) : (0))))))

#define CB1 ((board[pos.y1][pos.x1] >= '1' && \
	      board[pos.y1][pos.x1] <= '5') && \
	     (pos.y1 != old_pos.y1 || \
	      pos.x1 != old_pos.x1) && \
	     (pos.y1 != old_pos.y2 || \
	      pos.x1 != old_pos.x2) && \
	     (pos.y1 != old_pos.y3 || \
	      pos.x1 != old_pos.x3) && \
	     (pos.y1 != old_pos.y4 || \
	      pos.x1 != old_pos.x4))

#define CB2 ((board[pos.y2][pos.x2] >= '1' && \
	      board[pos.y2][pos.x2] <= '5') && \
	      (pos.y2 != old_pos.y1 || \
	       pos.x2 != old_pos.x1) && \
	     (pos.y2 != old_pos.y2 || \
	      pos.x2 != old_pos.x2) && \
	     (pos.y2 != old_pos.y3 || \
	      pos.x2 != old_pos.x3) && \
	     (pos.y2 != old_pos.y4 || \
	      pos.x2 != old_pos.x4))

#define CB3 ((board[pos.y3][pos.x3] >= '1' && \
	      board[pos.y3][pos.x3] <= '5') && \
	     (pos.y3 != old_pos.y1 || \
	      pos.x3 != old_pos.x1) && \
	     (pos.y3 != old_pos.y2 || \
	      pos.x3 != old_pos.x2) && \
	     (pos.y3 != old_pos.y3 || \
	      pos.x3 != old_pos.x3) && \
	     (pos.y3 != old_pos.y4 || \
	      pos.x3 != old_pos.x4))

#define CB4 ((board[pos.y4][pos.x4] >= '1' && \
	      board[pos.y4][pos.x4] <= '5') && \
	     (pos.y4 != old_pos.y1 || \
	      pos.x4 != old_pos.x1) && \
	     (pos.y4 != old_pos.y2 || \
	      pos.x4 != old_pos.x2) && \
	     (pos.y4 != old_pos.y3 || \
	      pos.x4 != old_pos.x3) && \
	     (pos.y4 != old_pos.y4 || \
	      pos.x4 != old_pos.x4))

#define TURN_L ((l->turn == 1) ? \
		(new_pos.x1 = pos.x2, new_pos.y1 = pos.y2 - 1, \
		 new_pos.x3 = pos.x2, new_pos.y3 = pos.y2 + 1, \
		 new_pos.x4 = pos.x2 + 1, new_pos.y4 = pos.y2 + 1) : \
		((l->turn == 2) ? \
		 (new_pos.x1 = pos.x2 + 1, new_pos.y1 = pos.y2, \
		  new_pos.x3 = pos.x2 - 1, new_pos.y3 = pos.y2, \
		  new_pos.x4 = pos.x2 - 1, new_pos.y4 = pos.y2 + 1) : \
		 ((l->turn == 3) ? \
		  (new_pos.x1 = pos.x2, new_pos.y1 = pos.y2 + 1, \
		   new_pos.x3 = pos.x2, new_pos.y3 = pos.y2 - 1, \
		   new_pos.x4 = pos.x2 - 1, new_pos.y4 = pos.y2 - 1) : \
		  ((l->turn == 4) ? \
		   (new_pos.x1 = pos.x2 - 1, new_pos.y1 = pos.y2, \
		    new_pos.x3 = pos.x2 + 1, new_pos.y3 = pos.y2, \
		    new_pos.x4 = pos.x2 + 1, new_pos.y4 = pos.y2 - 1) : (0)))))

#define TURN_I (new_pos.x1 = pos.x2, \
		new_pos.y1 = pos.y2 - 1, \
		new_pos.x3 = pos.x2, \
		new_pos.y3 = pos.y2 + 1, \
		new_pos.x4 = pos.x2, \
		new_pos.y4 = pos.y2 + 2)

#define TURN_T1 (new_pos.x1 = pos.x2, \
		 new_pos.y1 = pos.y2 - 1, \
		 new_pos.x3 = pos.x2, \
		 new_pos.y3 = pos.y2 + 1, \
		 new_pos.x4 = pos.x2 - 1, \
		 new_pos.y4 = pos.y2)

#define TURN_T2 (new_pos.x1 = pos.x2 + 1, \
		 new_pos.y1 = pos.y2, \
		 new_pos.x3 = pos.x2 - 1, \
		 new_pos.y3 = pos.y2, \
		 new_pos.x4 = pos.x2, \
		 new_pos.y4 = pos.y2 - 1)

#define TURN_T3 (new_pos.x1 = pos.x2, \
		 new_pos.y1 = pos.y2 + 1, \
		 new_pos.x3 = pos.x2, \
		 new_pos.y3 = pos.y2 - 1, \
		 new_pos.x4 = pos.x2 + 1, \
		 new_pos.y4 = pos.y2)

#define TURN_T4 (new_pos.x1 = pos.x2 - 1, \
		 new_pos.y1 = pos.y2, \
		 new_pos.x3 = pos.x2 + 1, \
		 new_pos.y3 = pos.y2, \
		 new_pos.x4 = pos.x2, \
		 new_pos.y4 = pos.y2 + 1)

#define TURN_Z (new_pos.x1 = pos.x3 + 1, \
		new_pos.y1 = pos.y3 - 1, \
		new_pos.x2 = pos.x3 + 1, \
		new_pos.y2 = pos.y3, \
		new_pos.x4 = pos.x3, \
		new_pos.y4 = pos.y3 + 1)

#define TTR (piece1.name = 'i', piece1.L = 1, \
	     piece1.l = 4, piece1.color = 1, \
	     piece1.piece = "*\n*\n*\n*\n", \
	     piece2.name = 'l', piece2.L = 2, \
	     piece2.l = 3, piece2.color = 2, \
	     piece2.piece = "*\n*\n**\n", \
	     piece3.name = 'o', piece3.L = 2, \
	     piece3.l = 2, piece3.color = 3, \
	     piece3.piece = "**\n**\n", \
	     piece4.name = 't', piece4.L = 3, \
	     piece4.l = 2, piece4.color = 4, \
	     piece4.piece = "***\n *\n", \
	     piece5.name = 'z', piece5.L = 3, \
	     piece5.l = 2, piece5.color = 5, \
	     piece5.piece = "**\n **\n", \
	     add_list(game, piece1), \
	     add_list(game, piece2), \
	     add_list(game, piece3), \
	     add_list(game, piece4), \
	     add_list(game, piece5))

#define MHS (mvprintw(8, i, "\\"), \
	     mvprintw(9, 1, "|"),  \
	     mvprintw(9, i, "|"), \
	     mvprintw(10, 1, "| High Score: %d", score.hscore), \
	     mvprintw(10, i, "|"), \
	     mvprintw(11, 1, "| Score: %d", score.score), \
	     mvprintw(11, i, "|"), mvprintw(12, 1, "|"), \
	     mvprintw(12, i, "|"), \
	     mvprintw(13, 1, "| Lines: %d", score.line), \
	     mvprintw(13, i, "|"), \
	     mvprintw(14, 1, "| Level: %d", score.level), \
	     mvprintw(14, i, "|"), mvprintw(15, 1, "|"), \
	     mvprintw(15, i, "|"), \
	     mvprintw(16, 1, "| Timer: %d:%d", score.min, score.sec), \
	     mvprintw(16, i, "|"), mvprintw(17, 1, "|"), \
	     mvprintw(17, i, "|"), mvprintw(18, 1, "\\"))

#define DEBUG (mvprintw(8, 1, "Next : %s", \
			((option.w == 1) ? ("No") : ("Yes"))), \
	       mvprintw(9, 1, "Level : %i", option.l), \
	       mvprintw(10, 1, "Size : %i*%i", \
			option.map_row, option.map_col), \
	       mvprintw(11, 1, "Tetriminos : 5"), \
	       mvprintw(12, 1, \
			"Tetriminos : name : i : Size : 1*4 : Color : 1" \
			), mvprintw(13, 1, "*"), \
	       mvprintw(14, 1, "*"), mvprintw(15, 1, "*"), \
	       mvprintw(16, 1, "*"), mvprintw(17, 1, \
					      "Tetriminos : name : l : Size : 2*3 : Color : 2" \
					      ), mvprintw(18, 1, "*"), \
	       mvprintw(19, 1, "*"), mvprintw(20, 1, "*"), \
	       mvprintw(20, 2, "*"), mvprintw(21, 1, \
					      "Tetriminos : name : o : Size : 2*2 : Color : 3" \
					      ), mvprintw(22, 1, "*"), \
	       mvprintw(22, 2, "*"), mvprintw(23, 1, "*"), \
	       mvprintw(23, 2, "*"), mvprintw(24, 1, \
					      "Tetriminos : name : t : Size : 3*2 : Color : 4" \
					      ), mvprintw(25, 1, "*"), \
	       mvprintw(25, 2, "*"), mvprintw(25, 3, "*"), \
	       mvprintw(26, 2, "*"), mvprintw(27, 1, \
					      "Tetriminos : name : z : Size : 3*2 : Color : 5" \
					      ), mvprintw(28, 1, "*"), \
	       mvprintw(28, 2, "*"), mvprintw(29, 2, "*"), \
	       mvprintw(29, 3, "*"), mvprintw(30, 1, \
					      "Press a key to start Tetris" \
					      ), refresh())

#define DEBUG_K ((option.kl != '\0') ? \
		 ((option.kl == ' ') ? \
		  (mvprintw(2, 1, "Key Left : (space)")) : \
		  (mvprintw(2, 1, "Key Left : %c", option.kl))) : \
		 (mvprintw(2, 1, "Key Left : KEY_LEFT")), \
		 (option.kr != '\0') ? ((option.kr == ' ') ? \
					(mvprintw(3, 1, "Key Right : (space)")) : \
					(mvprintw(3, 1, "Key Right : %c", option.kr))) : \
		 (mvprintw(3, 1, "Key Right : KEY_RIGHT")), \
		 (option.kt != '\0') ? ((option.kt == ' ') ? \
					(mvprintw(4, 1, "Key Turn : (space)")) : \
					(mvprintw(4, 1, "Key Turn : %c", option.kt))) : \
		 (mvprintw(4, 1, "Key Turn : KEY_UP")), \
		 (option.kd != '\0') ? ((option.kd == ' ') ? \
					(mvprintw(5, 1, "Key Drop : (space)")) : \
					(mvprintw(5, 1, "Key Drop : %c", option.kd))) : \
		 (mvprintw(5, 1, "Key Drop : KEY_DOWN")), \
		 (option.kq != '\0') ? ((option.kq == ' ') ? \
					(mvprintw(6, 1, "Key Quit : (space)")) : \
					(mvprintw(6, 1, "Key Quit : %c", option.kq))) : \
		 (mvprintw(6, 1, "Key Quit : KEY_ESC")), \
		 (option.kp != '\0') ? ((option.kp == ' ') ? \
					(mvprintw(7, 1, "Key Pause : (space)")) : \
					(mvprintw(7, 1, "Key Pause : %c", option.kp))) : \
		 (mvprintw(7, 1, "Key Pause : (space)")))

#define SET_OPTION ((match(board[i], "--help") == 1) ? \
		    (option.h = 1) : \
		    ((match(board[i], "-l") == 1 || \
		      match(board[i], "--level") == 1) ? \
		     (option.l = get_level(board[i])) : \
		     ((match(board[i], "-kl") == 1 || \
		       match(board[i], "--key-left") == 1) ? \
		      (option.kl = get_key(board[i])) : \
		      ((match(board[i], "-kr") == 1 || \
			match(board[i], "--key-right") == 1) ? \
		       (option.kr = get_key(board[i])) : \
		       ((match(board[i], "-kt") == 1 || \
			 match(board[i], "--key-turn") == 1) ? \
			(option.kt = get_key(board[i])) : \
			((match(board[i], "-kd") == 1 || \
			  match(board[i], "--key-drop") == 1) ? \
			 (option.kd = get_key(board[i])) : \
			 ((match(board[i], "-kq") == 1 || \
			   match(board[i], "--key-quit") == 1) ? \
			  (option.kq = get_key(board[i])) : \
			  ((match(board[i], "-kp") == 1 || \
			    match(board[i], "--key-pause") == 1) ? \
			   (option.kp = get_key(board[i])) : \
			   ((match(board[i], "--map-size") == 1) ? \
			    (get_map(&option.map_row, &option.map_col, board[i])) : \
			    ((match(board[i], "-w") == 1 || \
			   match(board[i], "--without-next") == 1) ? \
			     (option.w = 1) : \
			     ((match(board[i], "-d") == 1 || \
			       match(board[i], "--debug") == 1) ? \
			      (option.d = 1) : (0))))))))))), ++i)

#define SET_CURSES (initscr(), start_color(), \
		    init_pair(1, COLOR_RED, COLOR_BLACK), \
		    init_pair(2, COLOR_GREEN, COLOR_BLACK), \
		    init_pair(3, COLOR_YELLOW, COLOR_BLACK), \
		    init_pair(4, COLOR_CYAN, COLOR_BLACK), \
		    init_pair(5, COLOR_MAGENTA, COLOR_BLACK), \
		    init_pair(6, COLOR_BLUE, COLOR_BLACK), \
		    curs_set(0), keypad(stdscr, TRUE), \
		    noecho(), (option.d == 1) ? \
		    (my_debug(option, game), getch()) : \
		    (0), ret = my_game(game, option), \
		    refresh(), endwin())

#define	INIT_GAME (var.timer = 0, score.min = 0, \
		   score.score = 0, score.lr = 0, \
		   score.level = option.l, \
		   next = gen_next(game), \
		   var.temps_init = time(NULL), \
		   var.temps_fin = var.temps_init, \
		   var.rep = 0, \
		   var.z = 1000 - \
		   (score.level * 100), \
		   (var.z < 100) ? (var.z = 100) : (0), \
		   gettimeofday(&(var.t0), 0), \
		   gettimeofday(&(var.t1), 0), score.hscore = read_hscore())

#define INIT_GAME2 (timeout(var.z/2), \
		    pos = init_pos(current, board, option.map_col))

#define INIT_GAME3 (old_pos = pos, var.same = 1, current.turn = 1)

#define SET_GAME (clear(), my_title(), \
		   ((var.temps_fin - var.temps_init - var.timer) == 60) ? \
		   (var.timer += 60, ++score.min) : (0), (score.lr >= 10) ? \
		   (score.lr -= 10, ++score.level, var.z -= 100, (var.z < 100) ? \
		   (var.z = 100) : (0)) : \
		   (0), score.sec = var.temps_fin - var.temps_init - var.timer, \
		   score.line = count_line(board, pos, old_pos), \
		   my_high_score(score), \
		   board = set_pos(board, pos, old_pos, \
				   current), old_pos = pos, (option.w == 0) ? \
		   (my_next(option.map_col, next)) : (0), \
		   my_show_board(board), refresh(), var.clavier = getch())

#define GT ((var.rep == 0 || \
	     (timedifference_msec(var.t0, var.t1) \
	      >= var.z && var.rep != 2)) ? \
	    (pos = down_pos(pos), gettimeofday(&(var.t0), 0)) : \
	    (var.rep = 0))

#define MG1 (pos = down_pos(pos), var.rep = 2)

#define MG2 (var.rep = 1, pos = check_border2(board, pos, old_pos, 0))

#define MG3 (pos = check_border2(board, pos, old_pos, 1), var.rep = 1)

#define MG4 (pos = turn(&current, pos, old_pos, board), var.rep = 1)

#define MGB1 ((option.kd != '\0') ? (var.clavier == option.kd) : \
	      (var.clavier == KEY_DOWN))

#define MGB2 ((option.kl != '\0') ? (var.clavier == option.kl) : \
	      (var.clavier == KEY_LEFT))

#define MGB3 ((option.kr != '\0') ? (var.clavier == option.kr) : \
	      (var.clavier == KEY_RIGHT))

#define MGB4 ((option.kt != '\0') ? (var.clavier == option.kt) : \
	      (var.clavier == KEY_UP))

#define MGB5 (var.clavier != KEY_UP || var.clavier != KEY_RIGHT || \
	      var.clavier != KEY_DOWN)

#define PG ((option.kp != '\0') ? (var.clavier == option.kp) : \
	    (var.clavier == ' '))

#define QG ((option.kq != '\0') ? (var.clavier == option.kq) : \
	    (var.clavier == 27))

#define KEY_REP		if (MGB1) \
    MG1; \
  else if (MGB2) \
    MG2; \
  else if (MGB3) \
    MG3; \
  else if (MGB4) \
    MG4; \
  else if (MGB5) \
    var.rep = 1;

#define END_GAME (current = next, next = gen_next(game), \
		  board = check_remove(board, &score.score, &score.lr))

#define GAME ((check_border(board, pos, old_pos) == 1) ? \
	      (var.same = 0) : (0), \
	      var.temps_fin = time(NULL), gettimeofday(&(var.t1), 0))

#endif /* !CAFE_H_ */
