/*
** my_free.c for my_free in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec 19 13:49:18 2013 moulin_c
** Last update Sat Dec 21 02:13:40 2013 moulin_c
*/

#include <stdlib.h>
#include "word_tab.h"

int	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
  return (1);
}
