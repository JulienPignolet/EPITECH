char	*my_revstr(char	*str)
{
  int   i;
  int   j;
  char  c;

  i = 0;
  j = 0;
  c = 0;
  while (str[i] != '\0')
    ++i;
  while (j < i)
    {
      --i;
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      ++j;
    }
  return (str);
}
