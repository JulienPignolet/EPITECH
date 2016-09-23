##
## Makefile for my_files in /home/pignol_j/rendu/tests/my_ls
## 
## Made by Julien Pignolet
## Login   <pignol_j@epitech.net>
## 
## Started on  Fri Nov 20 19:47:15 2015 Julien Pignolet
## Last update Fri Nov 27 13:19:47 2015 Julien Pignolet
##

NAME	= my_ls

SRC	= main.c \
	str_treatment.c \
	list_treatment.c \
	my_printf.c \
	my_strlen.c \
	my_putchar.c \
	my_putstr.c \
	my_print_unprintable.c \
	my_put_nbr.c \
	my_put_nbr_pos.c \
	my_putnbr_base.c \
	my_putnbr_base_ptr.c \
	my_log10.c \
	my_log_x.c \
	flags.c \
	unsigned_int_handlers.c \
	unsigned_int_handlers2.c \
	unsigned_int_handlers3.c \
	unsigned_long_int_handler.c \
	int_unsigned_int_handler.c \
	char_handler.c \
	struct_treatment.c \
	list_treatment2.c 

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
