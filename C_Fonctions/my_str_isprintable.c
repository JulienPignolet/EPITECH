int	my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 126 || str[i] < 33)
        return (0);
      else
        ++i;
    }
  return (1);
}
