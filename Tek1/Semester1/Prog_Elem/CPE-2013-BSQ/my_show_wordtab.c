/*
** my_show_wordtab.c for jour 08 in /home/moulin_c/rendu/Piscine C/Piscine-C-Jour_08/ex_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Nov 27 10:25:35 2013 moulin_c
** Last update Sun Dec  8 18:05:29 2013 moulin_c
*/

#include "bsq.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
}
