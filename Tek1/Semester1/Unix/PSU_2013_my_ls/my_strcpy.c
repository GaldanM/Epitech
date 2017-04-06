/*
** my_strcpy.c for my_strcpy in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 09:33:28 2013 moulin_c
** Last update Sun Dec  1 14:15:54 2013 moulin_c
*/

#include "my_ls.h"

char    *my_strcpy(char *dest, char *src)
{
  int	a;

  a = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (src[a] != '\0')
    {
      dest[a] = src[a];
      a++;
    }
  dest[a] = '\0';
  return (dest);
}
