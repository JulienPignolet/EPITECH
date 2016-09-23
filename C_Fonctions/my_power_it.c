int	my_power_it(int nb, int power)
{
  int	i;
  int	tamp_nb;

  i = 1;
  tamp_nb = nb;
  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  else
    {
      while (i != power)
	{
	  ++i;
	  nb *= tamp_nb;
	}
      return (nb);
    }
}
