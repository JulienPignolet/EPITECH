int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
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
