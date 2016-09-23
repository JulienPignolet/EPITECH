/*
** pushswap.h for Pushswap in /home/pignol_j/rendu/tests/pushswap
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Wed Nov 11 20:21:50 2015 Julien Pignolet
** Last update Fri Nov 20 14:51:08 2015 Julien Pignolet
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#define PUSH (push(list1, list2))
#define POP (push(list2, list1))
#define ROTATE (rotate(list1))
#define INIT (sort = 0, bonus = 0, list1 = NULL, list2 = NULL)

struct s_list
{
  int	nb;
  struct s_list	*next;
};

typedef struct s_list t_list;

int	my_atoi(char *);
int	my_atoi_error(char *);
int	my_list_size(t_list *);
int	check_sort(t_list **);
int	my_put_begin_list(t_list **, int);
int	my_put_end_list(t_list **, int);
int	my_show_list(t_list *);
int	my_free_list(t_list **);
int	my_calc_push(t_list *);
void	push(t_list **, t_list **);
void	rotate(t_list **);
void	my_pushswap(t_list **, t_list **, int);
void	my_pushswap2(t_list **, t_list **, int);
void	my_putchar(char);
void	my_putstr(char *);
void	my_put_nbr(int);

#endif //PUSHSWAP_H_
