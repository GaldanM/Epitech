/*
** eval_expr.c for Bistro in /home/moulin_c/rendu/Modules/C_Prog_Elem/Bistro/operations
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 10 16:04:35 2013 moulin_c
** Last update Sun Nov 10 17:05:39 2013 moulin_c
*/

#include "Bistromatique.h"

char	*eval_nbr2(char *str,char *nbr_2, int j, int i)
{
  i = i + 1;
  j = 0;
  while (CHIFFRE(str, i))
    {
      nbr_2[j] = str[i];
      i = i + 1;
      j = j + 1;
    }
  return (nbr_2);
}

char    *eval_expr(char *str)
{
  int   i;
  int   j;
  char  *nbr_1;
  char  *nbr_2;
  int	k;

  i = 0;
  i = strlen_mod(str, i);
  j = strlen_mod(str, i + 1);
  nbr_1 = malloc(i * sizeof(char));
  nbr_2 = malloc(j * sizeof(char));
  i = 0;
  while (CHIFFRE(str, i))
    {
      nbr_1[i] = str[i];
      i = i + 1;
    }
  k = i;
  nbr_2 = eval_nbr2(str, nbr_2, j, i);
  if (str[k] == '+')
    nbr_1 = my_add(nbr_1, nbr_2);
  else
    nbr_1 = my_sub(nbr_1, nbr_2);
  return (nbr_1);
}
