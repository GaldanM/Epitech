/*
** my_strncpy.c for my_strncp in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_02
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 12:04:01 2013 moulin_c
** Last update Fri Apr 18 04:21:25 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

char    *my_strncpy(char *dest, char *src, int nb)
{
  int	i;
  int	allok;

  i = 0;
  allok = my_strlen(src);
  if (allok > nb)
    allok = nb;
  if ((dest = malloc(sizeof(char) * (allok + 1))) == NULL)
    return (NULL);
  while (src[i] && i < nb)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
