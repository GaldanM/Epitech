/*
** my_strndup.c for lib in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Apr 26 13:43:13 2014 moulin_c
** Last update Sat Apr 26 13:53:01 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

char	*my_strndup(char *src, int nb)
{
  char	*new_str;
  int	i;
  int	len;

  i = 0;
  len = my_strlen(src) + 1;
  if (len > nb)
    len = nb + 1;
  if ((new_str = malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  while (src[i] && i < nb)
    {
      new_str[i] = src[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}
