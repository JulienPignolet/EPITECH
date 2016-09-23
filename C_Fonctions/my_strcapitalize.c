char	*my_strcapitalize(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (i == 0 && str[i] >=97 && str[i] <= 122)
	str[i] -= 32;
      if ((str[i] >= 32 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64))
	if (str[i + 1] >= 97 && str[i + 1] <= 122)
	  str[i + 1] -= 32;
      ++i;
    }
  return (str);
}
