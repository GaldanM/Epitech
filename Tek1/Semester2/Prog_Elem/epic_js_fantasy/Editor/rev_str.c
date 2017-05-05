/*
** rev_str.c for  in /home/medec_o/rendu/corewar/str_to_inst_tab/put_hexa
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Fri Apr  4 17:24:59 2014 medec_o
** Last update Sun May 11 20:58:22 2014 moulin_c
*/

#include <stdlib.h>
#include <string.h>

char	*rev_str(char *str)
{
  int	i;
  int	j;
  char	*n_str;

  j = strlen(str) - 1;
  i = 0;
  if ((n_str = malloc(strlen(str) * sizeof(char))) == NULL)
    exit(1);
  while (j >= 0)
    n_str[i++] = str[j--];
  n_str[i] = '\0';
  return (n_str);
}
