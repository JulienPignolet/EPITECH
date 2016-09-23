##
## Makefile for my_files in /home/pignol_j/rendu/tests/my_ls
## 
## Made by Julien Pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Fri Nov 20 19:47:15 2015 Julien Pignolet
## Last update Sat Mar 19 15:25:04 2016 Pignolet Julien
##

NAME	=	tetris

SRC	=	main.c \
		add_in_list.c \
		basics.c \
		move.c \
		move2.c \
		move3.c \
		div.c \
		option.c \
		print2.c \
		print.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g -lncurses

RM	=	rm -f

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	: 	clean
		$(RM) $(NAME)

re	: 	fclean all

.PHONY	:	all clean fclean re
