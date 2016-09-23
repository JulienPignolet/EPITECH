int	my_opfactorielle_rec(int nb, int i)
{
  if (nb == 0)
    return (1);
  else if (i != 0)
    {
      nb *= i;
      --i;
      if (nb < 0)
	return (0);
      my_opfactorielle_rec(nb, i);
    }
  else
    return (nb);
}

int	my_factorielle_rec(int nb)
{
  int	i;

  i = (nb - 1);
  return (my_opfactorielle_rec(nb, i));
}
