/*
** my.h for my.h in /home/pignol_j/rendu/Piscine_C_J09/include
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct  8 13:06:04 2015 julien pignolet
** Last update Tue Oct 20 20:54:39 2015 julien pignolet
*/

#ifndef MY_H_
#define MY_H_

void    my_putchar(char);
int     my_isneg(int);
int     my_put_nbr(int);
int     my_swap(int, int);
int     my_putstr(char*);
int     my_strlen(char*);
int     my_getnbr(char*);
void    my_sort_in_tab(int, int);
int     my_power_rec(int, int);
int     my_square_root(int);
int     my_is_prime(int);
int     my_find_prime_sup(int);
char    *my_strcpy(char*, char*);
char    *my_strncpy(char*, char*, int);
char    *revstr(char*);
char    *my_strstr(char*, char*);
int     my_strcmp(char*, char*);
int     my_strncmp(char*, char*, int);
char    *my_strupcase(char*);
char    *my_strlowcase(char*);
char    *my_strcapitalize(char*);
int     my_str_isalpha(char*);
int     my_str_isnum(char*);
int     my_str_islower(char*);
int     my_str_isupper(char*);
int     my_str_isprintable(char*);
int     my_showstr(char*);
int     my_showmem(char*, int);
char    *my_strcat(char*, char*);
char    *my_strncat(char*, char*, int);
int	my_show_wordtab(char**);
char	**my_str_to_wordtab(char*);
char	*my_strdup(char*);
char	*my_infin_add(char *, int);
char	*infin_sous(char *, char *, int, int);
char	*infin_add(char *, char *, int, int);
int	main_add_inf(char *, char *, int, int);
char	*my_memset(char *, int);
int	my_strcmp_inf(char *, char *);
int	my_complen(char *, char *);
int	my_putstr_inf(char *);
int	my_try_fonction(char *, char *);

#endif
