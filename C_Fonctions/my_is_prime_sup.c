int	my_is_prime_search(int nb)
{
  int	t;
  int	i;

  i = 0;
  t = 0;
  if (nb == 0 || nb == 1)
    return (0);
  else
    {
      while (t < nb)
	{
	  ++i;
	  t = i * i;
	}
      while (i > 1)
	{
	  if (nb % i == 0 && i != nb)
	    return (0);
	  --i;
	}
      return (1);
    }
}

int	my_find_prime_sup(int nb)
{
  while (my_is_prime_search(nb) != 1)
    ++nb;
  return (nb);
}
