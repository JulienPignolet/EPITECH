int	my_oppower_rec(int nb, int power, int i, int tamp_nb )
{
  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  else if (i == power)
    return (nb);
  else
    {
      ++i;
      nb *= tamp_nb;
      my_oppower_rec(nb, power, i, tamp_nb);
    }
}

int	my_power_rec(int nb, int power)
{
  int	i;
  int	tamp_nb;

  i = 1;
  tamp_nb = nb;
  return (my_oppower_rec(nb, power, i, tamp_nb));
}
