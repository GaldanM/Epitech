/*
** my_strdup.c for my_strdup in /home/moulin_c/rendu/Piscine-C-Jour_08/ex_01
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 10 08:52:29 2013 moulin_c
** Last update Tue Dec 31 09:26:58 2013 moulin_c
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	lenght;
  char	*str_new;

  lenght = my_strlen(src);
  if ((str_new = malloc(sizeof(char) * (lenght + 1))) == NULL)
    return (NULL);
  lenght = 0;
  while (src[lenght])
    str_new[lenght] = src[lenght++];
  str_new[lenght] = '\0';
  return (str_new);
}
