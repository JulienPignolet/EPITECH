##
## Makefile for my_select in /home/pignol_j/rendu/PSU_2015_my_popup
## 
## Made by Julien Pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Wed Dec  2 10:43:43 2015 Julien Pignolet
## Last update Mon Dec 14 13:08:05 2015 Julien Pignolet
##

NAME	= my_select

SRC	= main.c \
	list.c \
	basics.c

OBJ	= $(SRC:.c=.o)

CC	= gcc -g -lncurses

RM	= rm -f

FLAGS	= -Wextra -Wall -Werror -ansi -pedantic

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
