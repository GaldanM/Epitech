/*
** my_strlowcase.c for my_strlowcase in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_08
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 15:51:16 2013 moulin_c
** Last update Fri Apr 18 04:23:36 2014 moulin_c
*/

#include "my.h"

char	*my_strlowcase(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] >= 65 && str[a] <= 90)
        {
          str[a] = str[a] + 32;
          a = a + 1;
        }
      else
        {
          a = a + 1;
        }
    }
  return (str);
}
