/*
** my_ls_a.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Nov 30 16:57:35 2013 moulin_c
** Last update Sun Dec  1 18:32:38 2013 moulin_c
*/

#include "my_ls.h"

void	my_ls_a()
{
  char		**tab;
  int		i;

  tab = tab_name();
  i = 0;
  while (tab[i + 1] != 0)
    {
      my_printf("%s\n", tab[i]);
      i++;
    }
  free(tab);
}
