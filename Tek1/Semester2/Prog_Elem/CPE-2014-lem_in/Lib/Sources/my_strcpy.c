/*
** my_strcpy.c for my_strcpy in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 09:33:28 2013 moulin_c
** Last update Fri Apr 18 04:23:20 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	a;
  int	len;

  a = 0;
  len = my_strlen(src);
  if ((dest = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  while (src[a])
    {
      dest[a] = src[a];
      a++;
    }
  dest[a] = '\0';
  return (dest);
}
