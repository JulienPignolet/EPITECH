##
## Makefile for Makefile in /home/pignol_j/rendu/Piscine_C_infinadd
## 
## Made by julien pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Mon Oct 19 11:07:51 2015 julien pignolet
## Last update Tue Oct 20 20:55:16 2015 julien pignolet
##

NAME	= infin_add

SRC	= infin_add.c \
	infin_add2.c

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
