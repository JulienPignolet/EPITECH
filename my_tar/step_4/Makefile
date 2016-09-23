##
## Makefile for step_1 in /home/pignol_j/rendu/Rush1/step_1
## 
## Made by Julien Pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Sun Jan 10 15:15:04 2016 Julien Pignolet
## Last update Sun Jan 10 18:29:32 2016 Julien Pignolet
##

NAME	= my_tar

SRC	= main.c \
	file_info.c \
	helpers.c \
	parsing.c 

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
