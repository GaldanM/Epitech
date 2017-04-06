/*
** my_getnbr.c for my_getnbr in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct  4 10:05:59 2013 moulin_c
** Last update Tue Oct 22 11:11:00 2013 moulin_c
*/

int	calcul_getnbr(char *str, int a, int b, int sign)
{
  int	nb;
  int	result;
  int	retur;

  nb = 1;
  retur = 0;
  a = a - 1;
  while (b - 1 != a)
    {
      result = (str[a] - 48) * nb;
      nb = nb * 10;
      retur = retur + result;
      a = a - 1;
    }
  retur = retur * sign;
  return (retur);
}

int	my_getnbr(char *str)
{
  int	a;
  int	sign;
  int	b;
  int	c;

  a = 0;
  sign = 1;
  c = check_minus(str);
  while (str[a] == '+' || str[a] == '-')
    a = a + 1;
  if (str[a] >= 48 && str[a] <= 57)
    {
      b = a;
      if (c == 1)
	sign = -1;
      while (str[a] >= 48 && str[a] <= 57)
	a = a + 1;
      a = calcul_getnbr(str, a, b, sign);
      return (a);
    }
  return (a = '\0');
}
