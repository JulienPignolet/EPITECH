char	*my_strcat(char *dest, char *src)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
  while (dest[i] != '\0')
    {
      res[i] = dest[i];
      ++i;
    }
  while (src[j] != '\0')
    {
       res[i] = src[j];
      ++j;
      ++i;
    }
  res[i] = '\0';
  return (res);
}
