/*
** my_show_wordtab.c for jour 08 in /home/moulin_c/rendu/Piscine C/Piscine-C-Jour_08/ex_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Nov 27 10:25:35 2013 moulin_c
** Last update Tue Dec 31 09:22:20 2013 moulin_c
*/

#include <stdlib.h>
#include "word_tab.h"
#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
}
