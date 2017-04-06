/*
** strlen_mod.c for Bistro in /home/moulin_c/rendu/Modules/C_Prog_Elem/Bistro/operations
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 10 16:03:17 2013 moulin_c
** Last update Sun Nov 10 16:23:07 2013 moulin_c
*/

#include "Bistromatique.h"


int     strlen_mod(char *str, int i)
{
  while (CHIFFRE(str, i))
    {
      i = i + 1;
    }
  return (i);
}
