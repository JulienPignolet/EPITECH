##
## Makefile for minishell in /home/pignol_j/rendu/test/minishell1
## 
## Made by Julien Pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Fri Jan 22 08:54:43 2016 Julien Pignolet
## Last update Sun Jan 24 21:35:46 2016 Pignolet Julien
##

NAME	= mysh

SRC	= main.c \
	tab.c \
	basics.c \
	others.c \
	builtins.c

OBJ	= $(SRC:.c=.o)

CC	= gcc -g

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
