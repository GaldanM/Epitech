/*
** arrangement.c for Bistro in /home/moulin_c/rendu/Modules/C_Prog_Elem/Bistro/operations
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 10 16:02:28 2013 moulin_c
** Last update Sun Nov 10 16:21:38 2013 moulin_c
*/
#include "Bistromatique.h"

char    *arrangement(int k, int i, char *str_result)
{
  int j;

  j = 0;
  while (k != i)
    {
      str_result[j] = str_result[k + 3];
      k = k + 1;
      j = j + 1;
    }
  while (k != i + 3)
    {
      str_result[j] = '\0';
      j = j + 1;
      k = k + 1;
    }
  return (str_result);
}
