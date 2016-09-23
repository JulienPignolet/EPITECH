##
## Makefile for Makefile in /home/pignol_j/tests/Piscine_C_evalexpr
## 
## Made by Julien PIGNOLET
## Login   <pignol_j@epitech.net>
## 
## Started on  Fri Oct 30 08:34:25 2015 Julien PIGNOLET
## Last update Sun Nov  8 23:36:28 2015 Julien Pignolet
##

NAME	= libmy.a

SRC	= my_printf.c \
	my_strlen.c \
	my_putchar.c \
	my_putstr.c \
	my_print_unprintable.c \
	my_put_nbr.c \
	my_put_nbr_pos.c\
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
	char_handler.c

OBJ	= $(SRC:.c=.o)

RM	= rm -f

CC	= cc -c

$(NAME): $(OBJ)
	$(CC) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
