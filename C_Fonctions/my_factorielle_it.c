int	my_factorielle_it(int nb)
{
  int	i;

  i = (nb - 1);
  if (nb == 0)
      return (1);
  else
    {
      while (i != 0)
	{
	  nb *= i;
	  --i;
	  if (nb < 0)
	    return (0);
	}
      return (nb);
    }
}
