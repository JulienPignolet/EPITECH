/*
** my_tar.h for my_tar in /home/pignol_j/rendu/Rush1
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Jan 10 15:30:35 2016 Julien Pignolet
** Last update Sun Jan 10 15:53:53 2016 Julien Pignolet
*/

#ifndef MY_TAR_H_
#define MY_TAR_H_

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <ftw.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>

FILE *out;

typedef struct  __attribute__((packed)) s_header
{
	char name[100];
	char mode[8];
	char uid[8];
	char gid[8];
	char size[12];
	char mtime[12];
	char checksum[8];
	char type[1];
	char link[100];
	char padding[255];
} t_header;

void		fill_block(FILE *, int);
void		set_file_attribute(t_header, char *);
int		get_file(const char *, const struct stat *, int);
int		tar(FILE *, char *, int, const struct stat *);
int		un_tar(char *);
t_header	parse_header(char *);

#endif /* !MY_TAR_H_ */
