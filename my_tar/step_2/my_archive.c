/*
** my_archive.c for my_archive in /home/pignol_j/rendu/Rush1/step_1
** 
** Made by Julien Pignolet
** Login   <pignol_j@epitech.net>
** 
** Started on  Sun Jan 10 15:19:19 2016 Julien Pignolet
** Last update Sun Jan 10 18:56:21 2016 Julien Pignolet
*/

#include "my_tar.h"

void fill_block(FILE *stream, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      fputc(0, stream);
      i++;
    }
}

int get_file (const char *fpath, const struct stat *sb, int typeflag)
{
  if (typeflag == FTW_D)
    tar(out, (char *) fpath, FTW_D, sb);
  else
    tar(out, (char *) fpath, FTW_F, sb);
  return (0);
}

int tar(FILE *out, char *file, int file_type, const struct stat *buf)
{
  FILE			*in;
  t_header		my_struct;
  char			buffer[2000];
  const unsigned char	*header;
  unsigned int	        i;
  size_t		checksum;
  size_t		offset;
  size_t		read;

  checksum = 0;
  i = 0;
  if ((in = fopen(file, "r")) == NULL)
    {
      perror("fopen");
      return (0);
    }
  memset(&my_struct, 0, sizeof(t_header));
  snprintf(my_struct.name, 100, "%s", file);
  snprintf(my_struct.mode, 8, "%06o ", buf->st_mode);
  snprintf(my_struct.uid, 8, "%06o ", buf->st_uid);
  snprintf(my_struct.gid, 8, "%06o ", buf->st_gid);
  snprintf(my_struct.size, 12, "%011o ", (unsigned int) buf->st_size);
  snprintf(my_struct.mtime, 12, "%011o ", (unsigned int) buf->st_mtim.tv_sec);
  memset(my_struct.checksum, ' ', 8);
  if (file_type == FTW_D)
    my_struct.type[0] = '5';
  else
    my_struct.type[0] = '0';
  header = (const unsigned char *) &my_struct;
  while (i < sizeof(t_header))
    checksum += header[i++];
  snprintf(my_struct.checksum, 8, "%06o ", (unsigned int) checksum);
  fwrite(header, 1, sizeof(t_header), out);
  if (file_type != FTW_D)
    {
      while (!feof(in))
	{
	  if ((read = fread(buffer, 1, 2000, in)) == -1)
	    {
	      perror("fread");
	      return (0);
	    }
	  fwrite(buffer, 1, read, out);
	}
      offset = (size_t) (ftell(out) % 512);
      if (offset > 0)
	fill_block(out, (int) (512 - offset));
    }
  fclose(in);
  return (1);
}



int	main(int ac, char **av)
{
  int	i;
  struct stat	check;

  i = 2;
  if (ac >= 2)
    {
      if ((out = fopen(av[1], "wb")) == NULL)
	{
	  perror("fopen");;
	  return (1);
	}
      fseek(out, 0, SEEK_SET);
      while (i < ac)
	{
	  ftw(av[i], get_file, 1);
	  i++;
	}
      fclose(out);
      stat(av[1], &check);
      printf("%i\n", check.st_size);
      if (check.st_size == 0)
      	remove(av[1]);
    }
  else
    printf("Usage : ./my_archive archive file1 file2 ...\n");
  return (0);
}
