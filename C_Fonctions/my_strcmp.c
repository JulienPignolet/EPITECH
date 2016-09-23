int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (s1[i] - s2[i]);
      else if (s1[i] < s2[i])
	return (s1[i] - s2[i]);
      else
	++i;
    }
  return (0);
}
