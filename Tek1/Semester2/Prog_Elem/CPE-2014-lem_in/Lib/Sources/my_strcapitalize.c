/*
** my_strcapitalize.c for lib in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 18 03:33:24 2014 moulin_c
** Last update Fri Apr 18 04:21:58 2014 moulin_c
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	i++;
      if (str[i] && str[i] != ' ' && str[i] != '\t')
	{
	  if (str[i] >= 97 && str[i] <= 122)
	    str[i] = str[i] - 32;
	  i++;
	}
      while (str[i] && str[i] != ' ' && str[i] != '\t')
	i++;
    }
  return (str);
}
