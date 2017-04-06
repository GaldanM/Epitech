/*
** my_getnbr.c for getnbr in /home/di-mam_a/rendu/Piscine-C-Jour_04
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Wed Oct  9 09:02:26 2013 di-mam_a
** Last update Sun Apr 13 21:46:39 2014 di-mam_a
*/

int	calcul(char *str, int a, int e, int s)
{
  int	n;
  int	res;
  int	j;

  n = 1;
  j = 0;
  a = a - 1;
  while (e - 1 != a)
    {
      res = (str[a] - 48) * n;
      n = n * 10;
      j = j + res;
      a = a - 1;
    }
  j = j*s;
  return (j);
}

int	my_getnbr(char *str)
{
  int	a;
  int	s;
  int	e;

  a = 0;
  s = 1;
  while (str[a] != '\0')
    {
      if (str[a] >= 48 && str[a] <= 57)
	{
	  e = a;
	  if (str[a - 1] == 45)
	    s = -1;
	  while (str[a] >= 48 && str[a] <= 57)
	    a = a + 1;
	  a = calcul(str, a, e, s);
	  return (a);
	}
      a = a + 1;
    }
  return (0);
}
