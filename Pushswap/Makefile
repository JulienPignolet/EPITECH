##
## Makefile for Makefile in /home/pignol_j/tests/Piscine_C_evalexpr
## 
## Made by Julien PIGNOLET
## Login   <pignol_j@epitech.net>
## 
## Started on  Fri Oct 30 08:34:25 2015 Julien PIGNOLET
## Last update Fri Nov 20 14:49:11 2015 Julien Pignolet
##

NAME	= push_swap

SRC	= main.c \
	check_sort.c \
	sort.c \
	list_treatment.c \
	display.c \
	my_atoi.c \

OBJ	= $(SRC:.c=.o)

RM	= rm -f

CC	= gcc

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
