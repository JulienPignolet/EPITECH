int	my_getnbr(char *nb)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  while (nb[i])
    {
      if (nb[i] >= '0' && nb[i] <= '9')
        {
          res *= 10;
          res += nb[i] - '0';
        }
      else
	return (-1);
      ++i;
    }
  return (res);
}
