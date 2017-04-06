/*
** my_get_nbr_base.c for  in /home/moulin_c/rendu/Lib/
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Mar 12 16:29:09 2014 moulin_c
** Last update Thu Mar 20 11:50:50 2014 moulin_c
*/

#include <stdlib.h>
#include "../minitalk.h"

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

void	my_fill_nbr(char *nbr, int a)
{
  int	i;

  i = my_strlen(nbr);
  while (i < a)
    nbr[i++] = '0';
  nbr[i] = '\0';
}

char	*my_get_nbr_base(int nbr, char *base, int a)
{
  int	i;
  int	n_nbr;
  char	*rev_nbr;
  int	j;

  i = 1;
  j = 0;
  n_nbr = 0;
  if (nbr < 0)
    nbr = 32;
  if ((rev_nbr = malloc(a + 1 * sizeof(char))) == NULL)
    return (NULL);
  while (base[i] != '\0')
    i++;
  while (nbr > 0)
    {
      n_nbr = (nbr % i);
      rev_nbr[j++] = n_nbr + 48;
      nbr = nbr / i;
    }
  rev_nbr[j] = '\0';
  my_fill_nbr(rev_nbr, a);
  return (rev_nbr);
}
