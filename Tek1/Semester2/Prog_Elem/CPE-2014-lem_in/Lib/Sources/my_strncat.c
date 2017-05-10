/*
** my_strncat.c for my_strncat in /home/moulin_c/rendu/Piscine-C-Jour_07
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 15:53:55 2013 moulin_c
** Last update Fri Apr 18 04:21:28 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

char     *my_strncat(char *dest, char *src, int nb)
{
  char	*new;
  int	i;
  int	j;
  int	allok;

  i = 0;
  allok = my_strlen(src) + my_strlen(dest);
  if (allok > nb)
    allok = nb;
  if ((new = malloc(sizeof(char) * (allok + 1))) == NULL)
    return (NULL);
  while (i < nb && dest[i])
    {
      new[i] = dest[i];
      i++;
    }
  j = 0;
  while (i < nb && src[j])
    {
      new[i] = src[j];
      i++;
      j++;
    }
  new[i] = '\0';
  return (new);
}
