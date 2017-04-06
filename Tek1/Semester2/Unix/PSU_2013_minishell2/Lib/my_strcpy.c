/*
** my_strcpy.c for my_strcpy in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 09:33:28 2013 moulin_c
** Last update Tue Dec 31 09:51:04 2013 moulin_c
*/

#include <stdlib.h>
#include "../Includes/my.h"

char    *my_strcpy(char *dest, char *src)
{
  int	a;
  int	b;

  a = 0;
  b = my_strlen(src);
  if ((dest = malloc(sizeof(char) * (b + 1))) == NULL)
    return (NULL);
  while (a < b)
    {
      dest[a] = src[a];
      a++;
    }
  dest[a] = '\0';
  return (dest);
}
