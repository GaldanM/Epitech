/*
** my_putstr_rev.c for str_rev in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Nov 27 13:06:53 2013 moulin_c
** Last update Fri Apr 18 04:22:05 2014 moulin_c
*/

#include "my.h"

void	my_putstr_rev(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  i--;
  while (i >= 0)
    {
      my_putchar(str[i]);
      i--;
    }
}
