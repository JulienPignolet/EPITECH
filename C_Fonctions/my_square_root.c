int	my_square_root(int nb)
{
  int	a;

  a = 3;
  if ( nb > 2147395600 || nb < 0)
    return (0);
  else
  {
    while (a != 46341)
      {
	if (nb == (a * a))
	  return (a);
	else
	  ++a;
      }
    return (0);
  }
}
