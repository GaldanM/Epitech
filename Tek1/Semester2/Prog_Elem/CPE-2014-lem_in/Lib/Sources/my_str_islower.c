/*
** my_str_islower.c for my_str_islower in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_12
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 21:27:30 2013 moulin_c
** Last update Fri Apr 18 04:21:47 2014 moulin_c
*/

#include "my.h"

int     my_str_islower(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] < 97 || str[count] > 122)
        {
	  return (0);
	  count = count + 1;
	}
    }
  return (1);
}
