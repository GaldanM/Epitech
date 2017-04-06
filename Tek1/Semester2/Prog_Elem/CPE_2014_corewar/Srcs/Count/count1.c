/*
** count1.c for count1 in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Count
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 18:14:25 2014 moulin_c
** Last update Sun Apr 13 20:18:47 2014 moulin_c
*/

#include <stdlib.h>

int	my_aff(char **tab, int *octet, int pos)
{
  if (tab[1] && tab[2] && tab[3])
    check_type(tab, pos);
  *(octet) = 3;
}

int	my_add(char **tab, int *octet, int pos)
{
  check_type(tab, pos);
  *(octet) = 5;
}

int     my_live(char **tab, int *octet, int pos)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  check_type(tab, pos);
  *(octet) = 5;
}

int	my_sti(char **tab, int *octet, int pos)
{
  *(octet) = 0;
  check_type(tab, pos);
  if (tab[1])
    {
      *(octet) = count_octet_param(tab[1]);
      *(octet) += 6;
      if (tab[2] && tab[2][0] == 'r')
	*(octet) -= 1;
      if (tab[3] && tab[3][0] == 'r')
	*(octet) -= 1;
    }
}

int	my_st(char **tab, int *octet, int pos)
{
  int	i;

  i = 0;
  check_type(tab, pos);
  while (tab[i] != NULL)
    *(octet) = *(octet) + count_octet_param(tab[i++]);
  *(octet) += 2;
}
