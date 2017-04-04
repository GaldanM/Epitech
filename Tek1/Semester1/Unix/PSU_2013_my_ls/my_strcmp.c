/*
** my_strcmp.c for my_strcmp in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 10:14:57 2013 moulin_c
** Last update Sun Dec  1 10:43:38 2013 moulin_c
*/

#include "my_ls.h"

void	my_manage_cmp(char *str1, char *str2, int *i)
{
  if (str1[*i] >= 'A' && str1[*i] <= 'Z')
    str1[*i] = str1[*i] + 32;
  if (str2[*i] >= 'A' && str2[*i] <= 'Z')
    str2[*i] = str2[*i] + 32;
  if (str1[*i] == '.')
    str1[*i] = '_';
  if (str2[*i] == '.')
    str2[*i] = '_';
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;
  int   result;
  char	*str1;
  char	*str2;

  str1 = my_strcpy(str1, s1);
  str2 = my_strcpy(str2, s2);
  i = 0;
  while (str1[i] != '\0' || str2[i] != '\0')
    {
      my_manage_cmp(str1, str2, &i);
      if (str1[i] != str2[i])
        {
          result = str1[i] - str2[i];
          return (result);
        }
      i++;
    }
  free (str1);
  free (str2);
}
