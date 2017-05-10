/*
** my_getnbr.c for lib in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 18 03:20:58 2014 moulin_c
** Last update Fri Apr 18 04:22:55 2014 moulin_c
*/

#include "my.h"

int	calcul_getnbr(char *str, int i, int j, int sign)
{
  int	nb;
  int	result;
  long	ret;

  nb = 1;
  ret = 0;
  while (j - 1 < i)
    {
      result = (str[i] - 48) * nb;
      nb = nb * 10;
      ret = ret + result;
      i--;
    }
  if (ret > 2147483647 && sign > 0)
    return (0);
  else if (ret > 2147483648 && sign < 0)
    return (0);
  ret = ret * sign;
  return (ret);
}

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	sign;

  i = 0;
  sign = 1;
  while (str[i] != '\0')
    {
      if (str[i] >= 48 && str[i] <= 57)
	{
	  j = i;
	  if (str[i - 1] == '-')
	    sign = -1;
	  while (str[i] >= 48 && str[i] <= 57)
	    i++;
	  return (calcul_getnbr(str, --i, j, sign));
	}
      i++;
    }
  return (0);
}
