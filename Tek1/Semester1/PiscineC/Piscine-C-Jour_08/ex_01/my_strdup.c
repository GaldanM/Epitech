/*
** my_strdup.c for my_strdup in /home/moulin_c/rendu/Piscine-C-Jour_08/ex_01
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 10 08:52:29 2013 moulin_c
** Last update Thu Oct 10 19:36:41 2013 moulin_c
*/

#include <stdlib.h>

char	*my_strdup(char *str)
{
  int	lenght;
  char *str_new;

  lenght = my_strlen(str);
  str_new = malloc(lenght);
  str_new = str;
  if (str_new == NULL)
    return (NULL);
  return (str_new);
}
