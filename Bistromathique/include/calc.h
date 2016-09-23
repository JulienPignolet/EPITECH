/*
** calc.h for calc.h in /home/pignol_j/rendu/Piscine_C_evalexpr/include
** 
** Made by Julien PIGNOLET
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct 29 15:26:29 2015 Julien PIGNOLET
** Last update Wed Nov  4 17:24:15 2015 Arthur Hakobian
*/

#ifndef CALC_H_
#define CALC_H_

char	*remove0(char *);
char	*remove00(char *, int);
char	*my_remove000(char *);
char	*my_removeminus(char *);
char	*infin_sous(char *, char *, int, int, int);
char	*infin_add(char *, char *, int, int, int);
char	*main_add_inf2(char *, char *, int, int);
char	*main_add_inf(char *, char*, int, int);
char	*infin_mult2(char *, char *);
char	*infin_mult(char *, char*);
char	*my_str_nospace(char *);
int	try_sign(char *, char *);
int	my_try_fonction(char *, char *);
int	my_complen(char *, char *);
int	my_strcmp_inf(char *, char *);
char	*eval_expr(char *,char *, char *, unsigned int);
char	*factors(char **);
char	*summands(char **);
char	*number(char **);
int	my_strtol(char *, char **);
char	*my_stack_nbr(char *);
char	*infin_div(char *, char *);
char	*infin_div2(char *, char *, int, int);
int	try_null(char *);
int	my_strcmp_div(char *, char *);
char	*my_div_sous(char *);
char	*my_nbr_to_str(int);
char	*my_add_to_str(char *, char *, int);
char	*my_add_to_str2(char *, char *);
char	*my_memset(char *, int);
int	my_atoi(char *);
char	*get_expr(unsigned int);
char	*infin_mod(char *, char *);
char	*stand(char *, int , int, int);

#endif
