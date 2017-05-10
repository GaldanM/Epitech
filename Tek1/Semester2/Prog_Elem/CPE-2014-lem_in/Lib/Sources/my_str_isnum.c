/*
** my_str_isnum.c for my_str_isnum in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_11
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 21:11:46 2013 moulin_c
** Last update Fri Apr 18 04:23:29 2014 moulin_c
*/

#include "my.h"

int	my_str_isnum(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] < 48 || str[count] > 57)
	{
	  return (0);
	}
      count = count + 1;
    }
  return (1);
}
