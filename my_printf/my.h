/*
** my.h for my.h in /home/pignol_j/my_printf
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sat Nov  7 12:54:39 2015 Julien Pignolet
** Last update Sat Nov 14 21:22:17 2015 Julien Pignolet
*/

#ifndef MY_H_
#define MY_H_

#define TEST0 (try_conversion_specifier(format) == 0)
#define TEST1 ((try_conversion_specifier(format) == 1))
#define TEST2 ((try_conversion_specifier(format) == 2))
#define TEST3 ((try_conversion_specifier(format) == 3))
#define TEST4 ((try_conversion_specifier(format) == 4))
#define TEST5 ((try_conversion_specifier(format) == 5))
#define TEST6 ((try_conversion_specifier(format) == 6))
#define RESET (reset_struct(flag), format += 1)
#define SEARCH (flag_search(flag, format), format += 1)
#define DISPLAY (my_putchar(*format), format += 1)
#define UIH (unsigned_int_handler)
#define UILH (unsigned_long_int_handler)
#define HEXA_MAJ ("0123456789ABCDEF")
#define HEXA_MIN ("0123456789abcdef")
#define OCTALE ("01234567")
#define BINAIRE ("01")

struct s_flag
{
  int	flag_sharp;
  int	flag_zero;
  int	flag_space;
  int	flag_plus;
  int	flag_minus;
};

typedef struct s_flag t_flag;

void	my_putchar(char);
void	my_putstr(char *);
void	my_print_unprintable(char *);
void	my_put_nbr(int);
void	my_put_nbr_pos(unsigned int);
void	my_putnbr_base(unsigned int, char *);
void	my_putnbr_base_ptr(unsigned long int, char *);
void	int_handler(int, t_flag *);
void	int_handler2(int, t_flag *, int, int);
void	unsigned_int_handler(unsigned int, char *, t_flag *);
void	u_handler(unsigned int, char *, t_flag *);
void	b_handler(unsigned int, char *, t_flag *);
void	b_handler2(unsigned int, char *, t_flag *, int);
void	c_handler(unsigned int, char *, t_flag *);
void	o_handler(unsigned int, char *, t_flag *);
void	o_handler2(unsigned int, char *, t_flag *, int);
void	x_handler(unsigned int, char *, t_flag *);
void	x_handler2(unsigned int, char *, t_flag *, int);
void	X_handler(unsigned int, char *, t_flag *);
void	X_handler2(unsigned int, char *, t_flag *, int);
void	unsigned_long_int_handler(unsigned long int, t_flag *);
void	unsigned_long_int_hand2(unsigned long int, t_flag *, int, int);
void	char_handler(char *, char *, t_flag *);
void	flag_search(t_flag *, char *);
void	text_handler(char *, t_flag *);
void	reset_struct(t_flag *);
int	my_log10(unsigned int);
int	my_log_x(unsigned int, char *);
int	my_strlen(char *);
int	try_conversion_specifier(char *);

#endif
