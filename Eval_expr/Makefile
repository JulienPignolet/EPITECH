##
## Makefile for Makefile in /home/pignol_j/rendu/Piscine_C_infinadd
## 
## Made by julien pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Mon Oct 19 11:07:51 2015 julien pignolet
## Last update Thu Oct 22 00:45:39 2015 julien pignolet
##

NAME	= eval_expr

SRC	= eval_expr.c \
	eval_expr2.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

LIB	= -lmy -L./lib

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
