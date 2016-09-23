##
## Makefile for makefile in /home/hakobi_a/Sudoki-Bi
## 
## Made by hakobi_a
## Login   <hakobi_a@epitech.net>
## 
## Started on  Sat Feb 27 00:31:42 2016 hakobi_a
## Last update Sun Feb 28 18:42:51 2016 Pignolet Julien
##

NAME	=	sudoki-bi

SRC	=	main.c \
		tab.c \
		add_in_list.c \
		check.c \
		check2.c \
		check3.c

RM	=	rm -rf

CC	=	gcc -g

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
