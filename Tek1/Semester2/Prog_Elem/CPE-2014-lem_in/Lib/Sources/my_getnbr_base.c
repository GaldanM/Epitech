/*
** my_getnbr_base.c for lib in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 18 08:57:17 2014 moulin_c
** Last update Fri Apr 18 10:18:01 2014 moulin_c
*/

#include "my.h"

int	checks_getnbrbase(char *str, char *base)
{
  int	i;
  int	j;

  if (str[0] == '\0' || base[0] == '\0')
    return (1);
  i = 0;
  while (base[i])
    {
      j = i + 1;
      while (base[j])
	{
	  if (base[j] == base[i])
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	find_pos(char letter, char *base)
{
  int	i;

  i = 0;
  while (base[i])
    {
      if (base[i] == letter)
	return (i);
      i++;
    }
  return (-1);
}

int	get_nbr_base(char *str, int len_base, char *base)
{
  int	i;
  int	j;
  int	nbr;
  int	mult;
  int	result;

  i = my_strlen(str) - 1;
  j = 0;
  result = 0;
  while (i >= 0)
    {
      if ((nbr = find_pos(str[i], base)) == -1)
	return (-1);
      mult = my_power_it(len_base, j);
      result = result + nbr * mult;
      j++;
      i--;
    }
  return (result);
}

int	my_getnbr_base(char *str, char *base)
{
  int	len_base;
  int	nbr;
  int	sign;

  sign = 1;
  if (str[0] == '-')
    {
      sign = -1;
      str = str + 1;
    }
  len_base = my_strlen(base);
  if (checks_getnbrbase(str, base))
    return (0);
  if ((nbr = get_nbr_base(str, len_base, base)) == -1)
    return (0);
  return (nbr * sign);
}
