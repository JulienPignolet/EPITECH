void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      ++i;
    }
}
