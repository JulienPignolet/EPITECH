/*
** my_unarchive.c for my_unarchive in /home/pignol_j/rendu/Rush1/step_1
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Jan 10 15:19:46 2016 Julien Pignolet
** Last update Sun Jan 10 17:53:04 2016 Julien Pignolet
*/

#include "my_tar.h"

t_header parse_header(char *header)
{
  t_header	my_struct;
  struct stat	st = {0};
  char		*endptr;
  long		value;

  strncpy(my_struct.name, header, 100);
  strncpy(my_struct.mode, header + 100, 108);
  strncpy(my_struct.uid, header + 108, 116);
  strncpy(my_struct.gid, header + 116, 124);
  strncpy(my_struct.size, header + 124, 136);
  strncpy(my_struct.mtime, header + 136, 148);
  strncpy(my_struct.checksum, header + 148, 156);
  strncpy(my_struct.type, header + 156, 157);
  if (my_struct.type[0] == '5')
    {
      if (stat(my_struct.name, &st) == -1)
	{
	  value = strtol(my_struct.mode, &endptr, 8);
	  mkdir(my_struct.name, (__mode_t) value);
	}
    }
  return (my_struct);
}

void set_file_attribute(t_header header, char *file)
{
  struct utimbuf	new_times;
  char			*endptr;
  long			value;

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

int un_tar(char *file)
{
  FILE		*in;
  FILE		*out;
  t_header	header;
  char		buffer_header[512];
  char		*endptr;
  char		*buffer_file;
  long		file_size;
  size_t	read;
  size_t	offset;

  if ((in = fopen(file, "rb")) == NULL)
    {
      perror("fopen");
      return (0);
    }
  fseek(in, 0, SEEK_SET);
  while (!feof(in))
    {
      if ((fread(buffer_header, 1, 512, in)) == -1)
	{
	  perror("fread");
	  return (0);
	}
      if (buffer_header[0] == '\0')
	{
	  fclose(in);
	  return (1);
	}
      header = parse_header(buffer_header);
      file_size = strtol(header.size, &endptr, 8);
      if (header.type[0] != '5')
	{
	  buffer_file = malloc(sizeof(char) * file_size + 1);
	  memset(buffer_file, 0, (size_t) (file_size + 1));
	  if ((out = fopen(header.name, "wb")) == NULL)
	    {
	      perror("fopen");
	      return (0);
	    }
	  set_file_attribute(header, header.name);
	  if ((read = fread(buffer_file, 1, (size_t) file_size, in)) == -1)
	    {
	      perror("fread");
	      return (0);
	    }
	  if (read <= 0)
	    {
	      fclose(out);
	      fclose(in);
	      return (1);
	    }
	  fwrite(buffer_file, 1, read, out);
	  offset = (size_t) (ftell(in) % 512);
	  if (offset > 0)
	    if ((fread(buffer_header, 1, 512 - offset, in)) == -1)
	      {
		perror("fread");
		return (0);
	      }
	  free(buffer_file);
	  fclose(out);
	}
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    un_tar(av[1]);
  else
    printf("Usage : ./my_unarchive archive\n");
  return (0);
}
