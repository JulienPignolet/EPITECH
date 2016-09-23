##
## Makefile for BSQ in /home/pignol_j/rendu/tests/BSQ
## 
## Made by Julien Pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Mon Dec 14 13:07:19 2015 Julien Pignolet
## Last update Wed Dec 16 21:05:36 2015 Julien Pignolet
##

NAME	= bsq

SRC	= main.c \
	basics.c \
	load_array.c

OBJ	= $(SRC:.c=.o)

CC	= gcc -g

RM	= rm -f

#CFLAGS	= -Wextra -Wall -Werror -ansi -pedantic

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
