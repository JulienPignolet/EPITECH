int	my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 57 || str[i] < 48)
	return (0);
      ++i;
    }
  return (1);
}
