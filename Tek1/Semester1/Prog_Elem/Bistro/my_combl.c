/*
** my_combl.c for Bistro in /home/moulin_c/rendu/Modules/C_Prog_Elem/Bistro/operations
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 10 16:05:10 2013 moulin_c
** Last update Sun Nov 10 16:23:34 2013 moulin_c
*/

#include "Bistromatique.h"

char    *my_combl(int i, int j, char *smallnb)
{
  char  *str;
  int   z;
  int   a;
  int   f;

  f = 0;
  j = COMPARE_LESS(i, j);
  z = COMPARE_MORE(i, j) - COMPARE_LESS(i, j);
  str = malloc((1 + i) * sizeof(char));
  i = i - 1;
  str[i] = '\0';
  while (j != -1)
    {
      j = j - 1;
      str[z] = smallnb[f];
      z = z + 1;
      f = f + 1;
    }
  z = z - f;
  while (z != 0)
    {
      z = z - 1;
      str[z] = '0';
    }
  return (str);
}
