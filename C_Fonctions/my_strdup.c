char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  dest = malloc(my_strlen(src));
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
