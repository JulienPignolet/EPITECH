char	*my_strstr(char	*str, char *to_find)
{
  int	i;
  int	j;
  int	pr_to_find;

  j = 0;
  i = 0;
  while (to_find[i] != '\0')
    {
      i = 0;
      while (str[j] != to_find[i] && str[j] != '\0')
	++j;
      if (str[j] == '\0')
	return (0);
      pr_to_find = j;
      while (str[j] == to_find[i] && to_find[i] != '\0')
	{
	  ++j;
	  ++i;
	}
    }
  return (&str[pr_to_find]);
}
