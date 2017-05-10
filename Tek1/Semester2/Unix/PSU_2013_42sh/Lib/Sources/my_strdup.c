/*
** my_strdup.c for lib in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 18 03:25:02 2014 moulin_c
** Last update Sat May 24 15:37:51 2014 doghri_f
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	i;
  int	lenght;
  char	*str_new;

  lenght = my_strlen(src);
  if ((str_new = malloc(sizeof(char) * (lenght + 1))) == NULL)
    return (NULL);
  i = 0;
  while (src[i])
    {
      str_new[i] = src[i];
      i++;
    }
  str_new[i] = '\0';
  return (str_new);
}
