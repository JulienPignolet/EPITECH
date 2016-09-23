/*
** main.c for main in /home/desver_f/rendu/Rush1
**
** Made by Flavian DESVERNE
** Login   <desver_f@epitech.net>
**
** Started on  Fri Jan  8 22:02:47 2016 Flavian DESVERNE
** Last update Sun Jan 10 21:11:53 2016 Flavian DESVERNE
*/

#include "tar.h"

int add_file_tar(FILE *out, char *file, int file_type, const struct stat *buf)
{
  FILE *in;
  size_t offset;
  t_header my_struct;
  const unsigned char *header;
  int i;
  char buffer[2000];
  size_t checksum;
  size_t read;

  checksum = 0;
  i = 0;
  if ((in = fopen(file, "rb")) == NULL) {
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
  (file_type == FTW_D) ? (my_struct.type[0] = '5') : (my_struct.type[0] = '0');
  header = (const unsigned char *) &my_struct;
  while (i < sizeof(t_header))
    checksum += header[i++];
  snprintf(my_struct.checksum, 8, "%06o ", (unsigned int) checksum);
  fwrite(header, 1, sizeof(t_header), out);
  if (file_type != FTW_D) {
    while (!feof(in)) {
      if ((read = fread(buffer, 1, 2000, in)) == -1) {
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
}

int get_file (const char *fpath, const struct stat *sb, int typeflag)
{
  if (typeflag == FTW_D)
    add_file_tar(out, (char *) fpath, FTW_D, sb);
  else
    add_file_tar(out, (char *) fpath, FTW_F, sb);
  if (params->c && params->v)
    printf("%s\n", fpath);
  return (0);
}

int un_tar(char *file, t_params *params)
{
  FILE *in;
  FILE *out;
  t_header header;
  size_t read;
  size_t offset;
  char *endptr;
  long file_size;

  if ((in = fopen(file, "rb")) == NULL) {
    perror("fopen");
    return (0);
  }
  fseek(in, 0, SEEK_SET);
  while (!feof(in))
    {
      char buffer_header[512];
      char *buffer_file;
      if ((fread(buffer_header, 1, 512, in)) == -1) {
	perror("fread");
	return (0);
      }
      if (buffer_header[0] == '\0')
	{
	  fclose(in);
	  return (1);
	}
      header = parse_header(buffer_header, params);
      file_size = strtol(header.size, &endptr, 8);
      if (header.type[0] != '5')
	{
	  buffer_file = malloc(sizeof(char) * file_size + 1);
	  memset(buffer_file, 0, (size_t) (file_size + 1));
	  if (params->x)
	    if ((out = fopen(header.name, "wb")) == NULL) {
	      perror("fopen");
	      return (0);
	    }
	  set_file_attribute(header, header.name);
	  if ((read = fread(buffer_file, 1, (size_t) file_size, in)) == -1) {
	    perror("fread");
	    return (0);
	  }
	  if (read <= 0)
	    {
	      if (params->x)
		fclose(out);
	      fclose(in);
	      return (1);
	    }
	  if (params->x)
	    fwrite(buffer_file, 1, read, out);
	  offset = (size_t) (ftell(in) % 512);
	  if (offset > 0)
	    if ((fread(buffer_header, 1, 512 - offset, in)) == -1)
	      {
		perror("fread");
		return (0);
	      }
	  free(buffer_file);
	  if (params->x)
	    fclose(out);
	}
    }
}

int tar(int ac, char **av, t_params *params)
{
  int i;

  i = params->index_start;
  if ((out = fopen(av[i++], "wb")) == NULL)
    {
      perror("fopen");
      return (0);
    }
  fseek(out, 0, SEEK_SET);
  while (i < ac)
    {
      ftw(av[i], get_file, 1);
      i++;
    }
  fclose(out);
}

int main(int ac, char **av)
{
  struct stat	check;

  params = init_params(params);
  parse_params(ac, av);
  if (params->c && params->f && params->x == 0 && ac > 3)
    {
      tar(ac, av, params);
      stat(av[params->index_start], &check);
      if (check.st_size == 0)
	remove(av[params->index_start]);
    }
  else if ((params->x || params->t) && params->f && params->c == 0 && ac > 2)
    un_tar(av[params->index_start], params);
  else
    printf("Usage: ./my_tar -xvf archive.tar (Extract)| ./my_tar -cvf archive.tar file1 file2... (Compress)\n");
  free(params);
  return (0);
}
