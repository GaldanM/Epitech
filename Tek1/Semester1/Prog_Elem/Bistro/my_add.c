/*
** my_add.c for Bistro in /home/dol/rendu/Bistromathique/test/operations
** 
** Made by moulin_c
** Login   <moulin_c@epitech.eu>
** 
** Started on  Mon Nov  4 13:18:36 2013 moulin_c
** Last update Sun Nov 10 17:10:27 2013 moulin_c
*/

#include "Bistromatique.h"

/*
int	sign(char *nbr_1, char *nbr_2)
{
  if (nbr_1[0] == '-' || nbr_2[0] == '-')
    {
      return (-1);
    }
  else
    return (0);
    }*/

char	*my_calc_add(int i, char *nbr_1, char *nbr_2)
{
  int	ciph_1;
  int	ciph_2;
  char	*str_result;
  int	result;
  int	carry;
  int	k;

  carry = 0;
  str_result = malloc(i + 3 * sizeof(char));
  k = i;
  k = k - 1;
  while (k != -1)
    {
      ciph_1 = nbr_1[k] - 48;
      ciph_2 = nbr_2[k] - 48;
      result = ciph_1 + ciph_2 + carry;
      carry = result / 10;
      result = result % 10;
      str_result[k + 3] = result + 48;
      k = k - 1;
    }
  str_result = if_carry(carry, k, i, str_result);
  return (str_result);
}


char	*my_add(char *nbr_1, char *nbr_2)
{
  int	i;
  int	j;
  char	*str_final;
  char	*smallnb;
  char	*highnb;
  
  highnb = COMPARE_NBR_MORE(nbr_1, nbr_2);
  smallnb = COMPARE_NBR_LESS(nbr_1, nbr_2);
  i = my_strlen(nbr_1);
  j = my_strlen(nbr_2);
  if (i != j)
    {
      highnb = COMPARE_NBR_MORE(nbr_1, nbr_2);
      smallnb = COMPARE_NBR_LESS(nbr_1, nbr_2);
      i = my_strlen(highnb);
      j = my_strlen(smallnb);
      smallnb = my_combl(i, j, smallnb);
      str_final = my_calc_add(i, highnb, smallnb);
      return (str_final);
    }
  str_final = my_calc_add(i, nbr_1, nbr_2);
  return (str_final);
}
