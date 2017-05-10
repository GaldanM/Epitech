/*
** epur_str.c for epur_str in /home/doghri_f/rendu
** 
** Made by doghri_f
** LoginOB   <doghri_f@epitech.net>
** 
** Started on  Fri Apr  4 17:28:54 2014 doghri_f
** Last update Sat Apr 26 14:53:51 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

int	my_epur_strlen(char *str)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (str[a] != '\0')
    {
      while (str[a] && (str[a] == ' ' || str[a] == '\t'))
	a++;
      b++;
      a++;
      if (str[a] == ' ' || str[a] == '\t')
	{
	  b++;
	  a++;
	  while (str[a] && (str[a] == ' ' || str[a] == '\t'))
	    a++;
	}
    }
  return (b);
}

char	*malloc_epur(char *str)
{
  char	*epur;

  if ((epur = malloc((my_epur_strlen(str) + 1) * sizeof(char))) == NULL)
    exit(1);
  return (epur);
}

char	*epur_str(char *str)
{
  int	b;
  int	a;
  char	*n_str;

  b = 0;
  a = 0;
  n_str = malloc_epur(str);
  while (str[a] != '\0')
    {
      while (str[a] && (str[a] == ' ' || str[a] == '\t'))
	a++;
      n_str[b++] = str[a++];
      if (str[a] == ' ' || str[a] == '\t')
	{
	  n_str[b++] = str[a++];
	  while (str[a] && (str[a] == ' ' || str[a] == '\t'))
	    a++;
	}
    }
  if (n_str[b - 1] == ' ')
    n_str[b - 1] = '\0';
  else
    n_str[b] = '\0';
  return (n_str);
}
