/*
** count3.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Count
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 18:27:08 2014 moulin_c
** Last update Sun Apr 13 20:49:37 2014 moulin_c
*/

#include <stdlib.h>

int	my_xor(char **tab, int *oct, int pos)
{
  int   i;

  i = 0;
  check_type(tab, pos);
  while (tab[i] != NULL)
    {
      *(oct) = *(oct) + count_octet_param(tab[i]);
      i++;
    }
  *(oct) += 2;
}

int	my_zjmp(char **tab, int *oct, int pos)
{
  check_type(tab, pos);
  if (tab[1])
    *(oct) = count_octet_param(tab[1]);
  *(oct) += 1;
}

int	my_lldi(char **tab, int *oct, int pos)
{
  my_ldi(tab, oct, pos);
}

int	my_ldi(char **tab, int *oct, int pos)
{
  check_type(tab, pos);
  if (tab[1] && tab[2] && tab[3])
    *(oct) = count_octet_param(tab[3]);
  *(oct) += 6;
  if (tab[1] && tab[3] && (tab[1][0] == 'r' || tab[2][0] == 'r'))
    *(oct)--;
}
