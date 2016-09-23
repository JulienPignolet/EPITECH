char	**str_tab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str[i] != '\0')
    {
      tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
      k = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
	  tab[j][k] = str[i];
	  ++i;
	  ++k;
	}
      (str[i] == ' ' || str[i] == '\t') ? (++i) : (0);
      tab[j][k] = '\0';
      ++j;
    }
  tab[j] = NULL;
  return (tab);
}
