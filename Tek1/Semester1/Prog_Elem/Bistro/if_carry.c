/*
** if_carry.c for Bistro in /home/moulin_c/rendu/Modules/C_Prog_Elem/Bistro/operations
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 10 16:05:46 2013 moulin_c
** Last update Sun Nov 10 18:05:09 2013 moulin_c
*/

#include "Bistromatique.h"

char    *if_carry(int carry, int k, int i, char *str_result)
{
  if (carry == 1)
    {
      str_result[k + 3] = carry + 48;
      str_result = arrangement(k, i, str_result);
    }
  else
    {
      k = k + 1;
      str_result = arrangement(k, i, str_result);
    }
  return (str_result);
}
