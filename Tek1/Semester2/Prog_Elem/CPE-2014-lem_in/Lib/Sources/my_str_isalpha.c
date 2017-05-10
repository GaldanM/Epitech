/*
** my_str_isalpha.c for my_str_isalpha in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_10
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 20:43:26 2013 moulin_c
** Last update Fri Apr 18 04:23:24 2014 moulin_c
*/

#include "my.h"

int	my_str_isalpha(char *str)
{
  int	count;
  int	b;

  b = 0;
  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] >= 65 && str[count] <= 90)
	b = 1;
      else if (str[count] >= 97 && str[count] <= 122)
	b = 1;
      else
	if (b == 1 || count == 0 )
	  return (0);
      count = count + 1;
    }
  return (1);
}
