##
## Makefile for step_1 in /home/pignol_j/rendu/Rush1/step_1
## 
## Made by Julien Pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Sun Jan 10 15:15:04 2016 Julien Pignolet
## Last update Sun Jan 10 15:59:45 2016 Julien Pignolet
##

NAME	= my_archive

NAME2	= my_unarchive

SRC	= my_archive.c

SRC2	= my_unarchive.c

OBJ	= $(SRC:.c=.o)

OBJ2	= $(SRC2:.c=.o)

CC	= gcc -g

RM	= rm -f

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

$(NAME2): $(OBJ2)
	$(CC) -o $(NAME2) $(OBJ2)

all: $(NAME) $(NAME2)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ2)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
