char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = -1;
  while(++i < n)
    dest[i] = src[i];
  if (n > i)
    dest[i] = '\0';
  return (dest);
}
