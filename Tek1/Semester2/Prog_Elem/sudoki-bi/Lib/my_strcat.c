/*
** my_strcat.c for my_strcat in /home/moulin_c/rendu/Piscine-C-Jour_07
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 15:16:47 2013 moulin_c
** Last update Sat Mar  1 17:06:49 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	a;
  int	b;
  int	len_d;
  int	len_s;
  char	*new;

  len_d = my_strlen(dest);
  len_s = my_strlen(src);
  if ((new = malloc(sizeof(char) * (len_d + len_s + 1))) == NULL)
    return (NULL);
  a = 0;
  b = 0;
  while (dest[a])
    new[a] = dest[a++];
  while (src[b])
    new[a++] = src[b++];
  new[a] = '\0';
  return (new);
}
