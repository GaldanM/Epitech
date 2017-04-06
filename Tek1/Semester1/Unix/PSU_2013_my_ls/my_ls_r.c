/*
** my_ls_r.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Nov 30 16:56:46 2013 moulin_c
** Last update Sun Dec  1 18:30:34 2013 moulin_c
*/

#include "my_ls.h"

void	my_ls_r()
{
  int	j;
  char	**tab;

  tab = tab_name_rev();
  j = 0;
  while (tab[j] != 0)
    {
      if (tab[j][0] == '.')
	j++;
      else
	my_printf("%s  ", tab[j++]);
    }
  free(tab);
  my_printf("\n");
}
