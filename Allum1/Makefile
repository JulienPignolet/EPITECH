##
## Makefile for Allum1 in /home/pignol_j/rendu/test/minishell1
## 
## Made by Julien Pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Fri Jan 22 08:54:43 2016 Julien Pignolet
## Last update Wed Feb 24 15:06:15 2016 Pignolet Julien
##

NAME	= allum1

SRC	= main.c \
	ai.c \
	allum2.c \
	allum.c \
	basics2.c \
	basics.c

OBJ	= $(SRC:.c=.o)

CC	= gcc -g -w

RM	= rm -f

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
