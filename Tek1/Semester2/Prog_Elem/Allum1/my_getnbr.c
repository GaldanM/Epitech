﻿/*
** my_getnbr.c for getnbr in /home/moulin_c/rendu/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Feb 10 14:48:13 2014 moulin_c
** Last update Mon Feb 10 14:48:17 2014 moulin_c
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

  a = 0;
  sign = 1;
  while (str[a] != '\0')
    {
      if (str[a] >= 48 && str[a] <= 57)
	{
	  b = a;
	  if (str[a - 1] == 45)
	    sign = -1;
	  while (str[a] >= 48 && str[a] <= 57)
	    a = a + 1;
	  a = calcul_getnbr(str, a, b, sign);
	  return (a);
	}
      a = a + 1;
    }
  return (a = '\0');
}