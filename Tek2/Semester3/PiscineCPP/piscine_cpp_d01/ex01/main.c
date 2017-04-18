/*
** main.c for menger in /home/moulin_c/rendu/piscine_cpp_d01/ex01
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  7 13:04:31 2015 Galdan MOULINNEUF
** Last update Wed Jan  7 13:11:12 2015 Galdan MOULINNEUF
*/

#include	<stdio.h>
#include	<stdlib.h>

void            menger(int size, int level, int x, int y);

int		calcul_getnbr(char *str, int i, int j, int sign)
{
  int		nb;
  int		result;
  long		ret;

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

int		my_getnbr(char *str)
{
  int		i;
  int		j;
  int		sign;

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

int		main(int argc, char **argv)
{
  int		size;
  int		depth;

  if (argc < 3)
    return (-1);
  size = my_getnbr(argv[1]);
  depth = my_getnbr(argv[2]);
  if (depth < size)
    menger(size, depth, 0, 0);
  return (0);
}
