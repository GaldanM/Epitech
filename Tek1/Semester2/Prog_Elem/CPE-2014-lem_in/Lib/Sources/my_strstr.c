/*
** my_strstr.c for my_strstr in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 16:44:51 2013 moulin_c
** Last update Fri Apr 18 04:23:42 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

void	my_find_strstr(char *str, char *to_find, int *key, int *save)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] && j < my_strlen(to_find))
    {
      if (str[i] == to_find[j])
	{
	  if (j == 0)
	    *save = i;
	  (*key)++;
	  j++;
	}
      else
	{
	  *save = 0;
	  *key = 0;
	  j = 0;
	}
      i++;
    }
}

char	*my_strstr(char *str, char *to_find)
{
  int	key;
  int	save;

  if (!to_find[0])
    return (str);
  key = 0;
  my_find_strstr(str, to_find, &key, &save);
  if (key == my_strlen(to_find))
    return (str + save);
  return (NULL);
}
