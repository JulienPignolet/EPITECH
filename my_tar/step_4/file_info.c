/*
** file_info.c for file_info in /home/pignol_j/rendu/tests/Rush1
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Jan 10 18:16:51 2016 Julien Pignolet
** Last update Sun Jan 10 18:16:53 2016 Julien Pignolet
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "tar.h"

char           *get_file_right(__mode_t mode)
{
  char *rights;
  rights = malloc(sizeof(char) * (10 + 1));
  memset(rights, 0, 11);
  rights[0] = (S_ISDIR(mode)) ? (char)'d' : (char)'-';
  rights[1] = (mode & S_IRUSR) ? (char)'r' : (char)'-';
  rights[2] = (mode & S_IWUSR) ? (char)'w' : (char)'-';
  rights[3] = (mode & S_IXUSR) ? (char)'x' : (char)'-';
  rights[4] = (mode & S_IRGRP) ? (char)'r' : (char)'-';
  rights[5] = (mode & S_IWGRP) ? (char)'w' : (char)'-';
  rights[6] = (mode & S_IXGRP) ? (char)'x' : (char)'-';
  rights[7] = (mode & S_IROTH) ? (char)'r' : (char)'-';
  rights[8] = (mode & S_IWOTH) ? (char)'w' : (char)'-';
  rights[9] = (mode & S_IXOTH) ? (char)'x' : (char)'-';
  return (rights);
}

void set_file_attribute(t_header header, char *file)
{
  struct utimbuf new_times;
  char *endptr;
  long value;

  value = strtol(header.mode, &endptr, 8);
  chmod(file, (__mode_t) value);
  value = strtol(header.gid, &endptr, 8);
  setgid((__gid_t) value);
  value = strtol(header.uid, &endptr, 8);
  setuid((__uid_t) value);
  value = strtol(header.mtime, &endptr, 8);
  new_times.actime = time(NULL);
  new_times.modtime = value;
  utime(file, &new_times);
}
