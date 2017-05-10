/*
** my_str_isprintable.c for my_str_is_printable in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_14
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 21:32:26 2013 moulin_c
** Last update Fri Apr 18 04:21:44 2014 moulin_c
*/

#include "my.h"

int     my_str_isprintable(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] < 21 || str[count] >= 127)
        {
	  return (0);
        }
      count = count + 1;
    }
  return (1);
}
