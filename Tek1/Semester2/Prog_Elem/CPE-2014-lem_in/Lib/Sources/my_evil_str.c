/*
** my_evil_str.c for my_evil_str in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 20:17:43 2013 moulin_c
** Last update Fri Apr 18 04:22:37 2014 moulin_c
*/

#include "my.h"

void	my_evil_str(char *str)
{
  int	k;
  int	g;
  int	i;

  i = 0;
  k = my_strlen(str) - 1;
  g = k;
  while (k > g / 2)
    {
      my_swap(&str[i], &str[k]);
      k--;
      i++;
    }
}
