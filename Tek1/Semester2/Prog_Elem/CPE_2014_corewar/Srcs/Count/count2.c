/*
** count2.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Count
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 18:23:45 2014 moulin_c
** Last update Sun Apr 13 20:50:19 2014 moulin_c
*/

#include <stdlib.h>

int	my_ld(char **tab, int *oct, int pos)
{
  int	i;

  *(oct) = 0;
  i = 1;
  check_type(tab, pos);
  while (tab[i] != NULL)
    {
      *(oct) = *(oct) + count_octet_param(tab[i]);
      i++;
    }
  *(oct) += 2;
}

int	my_lld(char **tab, int *oct, int pos)
{
  check_type(tab, pos);
  my_ld(tab, oct, pos);
}

int	my_sub(char **tab, int *oct, int pos)
{
  check_type(tab, pos);
  *(oct) = 5;
}

int	my_and(char **tab, int *oct, int pos)
{
  int	i;

  i = 0;
  check_type(tab, pos);
  while (tab[i] != NULL)
    {
      *(oct) = *(oct) + count_octet_param(tab[i]);
      i++;
    }
  *(oct) += 2;
}

int	my_or(char **tab, int *oct, int pos)
{
  int	i;

  i = 0;
  check_type(tab, pos);
  while (tab[i] != NULL)
    {
      *(oct) = *(oct) + count_octet_param(tab[i]);
      i++;
    }
  *(oct) += 2;
}
