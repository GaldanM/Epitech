/*
** my_putstr.c for my_putstr in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 18:51:01 2013 moulin_c
** Last update Sun May 25 07:58:41 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

int	 my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      if (my_putstr("(null)") == -1)
	return (-1);
    }
  else
    while (str[i])
      {
	if (my_putchar(str[i]) == -1)
	  return (-1);
	i++;
      }
  return (0);
}
