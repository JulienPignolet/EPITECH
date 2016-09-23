/*
** my_putchar.c for my_putchar in /home/pignol_j/mylib.c
** 
** Made by julien pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Thu Oct  8 14:01:50 2015 julien pignolet
** Last update Sat Nov  7 13:11:56 2015 Julien Pignolet
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
