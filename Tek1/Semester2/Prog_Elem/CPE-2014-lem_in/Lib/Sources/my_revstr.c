/*
** my_revstr.c for my_revstr in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 14:52:55 2013 moulin_c
** Last update Sat Apr 19 13:50:30 2014 moulin_c
*/

#include "my.h"

void	my_revstr(char *str)
{
  int	count;
  int	numb;

  numb = my_strlen(str) - 1;
  count = 0;
  while (count <= numb)
    {
      my_swap(&str[numb], &str[count]);
      count++;
      numb--;
    }
}
