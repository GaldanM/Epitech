/*
** my_show_wordtab.c for jour 08 in /home/moulin_c/rendu/Piscine C/Piscine-C-Jour_08/ex_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Nov 27 10:25:35 2013 moulin_c
** Last update Fri Feb 28 17:15:46 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/parser.h"
#include "../Includes/my.h"

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
