/*
** my_strdup.c for my_strdup in /home/moulin_c/rendu/Piscine-C-Jour_08/ex_01
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 10 08:52:29 2013 moulin_c
** Last update Fri Oct 11 20:24:19 2013 moulin_c
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	lenght;
  char *str_new;

  lenght = my_strlen(src);
  str_new = malloc(lenght);
  if (str_new == NULL)
    return (NULL);
  str_new = src;
  return (str_new);
}
