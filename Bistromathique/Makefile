##
## Makefile for Makefile in /home/pignol_j/tests/Piscine_C_evalexpr
## 
## Made by Julien PIGNOLET
## Login   <pignol_j@epitech.net>
## 
## Started on  Fri Oct 30 08:34:25 2015 Julien PIGNOLET
## Last update Sun Nov  1 21:10:20 2015 Julien Pignolet
##

NAME	= calc

SRC	= eval_expr.c \
	eval_expr2.c \
	infin_mult.c \
	infin_add.c \
	infin_add2.c \
	infin_div.c \
	infin_div2.c \
	infin_mod.c \
	my_atoi.c \
	get_expr.c \
	my_stand.c

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
