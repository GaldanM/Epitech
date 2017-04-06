/*
** my_strcat.c for my_strcat in /home/moulin_c/rendu/Piscine-C-Jour_07
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 15:16:47 2013 moulin_c
** Last update Sun Apr 13 15:46:18 2014 moulin_c
*/

#include <stdlib.h>

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i])
    i++;
  while (src[j])
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
  return (dest);
}
