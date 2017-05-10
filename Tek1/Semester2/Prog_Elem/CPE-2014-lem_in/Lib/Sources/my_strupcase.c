/*
** my_strupcase.c for my_strupcase in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_07
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 15:49:53 2013 moulin_c
** Last update Fri Apr 18 04:21:16 2014 moulin_c
*/

#include "my.h"

char    *my_strupcase(char *str)
{
  int   a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] >= 97 && str[a] <= 122)
        {
	  str[a] = str[a] - 32;
          a++;
        }
      else
	a++;
    }
  return (str);
}
