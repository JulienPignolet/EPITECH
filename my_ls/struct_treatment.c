/*
** struct_treatment.c for struct_treatment in /home/pignol_j/rendu/tests/my_ls
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Fri Nov 27 13:17:02 2015 Julien Pignolet
** Last update Sun Nov 29 15:45:20 2015 Julien Pignolet
*/

#include "ls.h"

void	init_option(t_option *option)
{
  option->o_l = 0;
  option->o_a = 0;
}

void	check_option(char *str, t_option *option)
{
  while (*str != '\0')
    {
      (*str == 'l') ? (option->o_l = 1) : (0);
      (*str == 'a') ? (option->o_a = 1) : (0);
      (*str == 'd') ? (option->o_d = 1) : (0);
      str += 1;
    }
}
