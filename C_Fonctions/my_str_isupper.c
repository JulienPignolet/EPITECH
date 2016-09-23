int	my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 90 || str[i] < 65)
      	return (0);
      else
	++i;
    }
  return (1);
}
