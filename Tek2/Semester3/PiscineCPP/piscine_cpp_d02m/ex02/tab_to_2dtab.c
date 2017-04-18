/*
** tab_to_2dtab.c for tab_to_2dtab in /home/moulin_c/rendu/piscine_cpp_d02m/ex02
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan  8 10:49:00 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 11:22:57 2015 Galdan MOULINNEUF
*/

#include	<stdlib.h>

void		tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int		i = 0;
  int		j = 0;
  int		k = 0;

  if (((*res) = malloc(sizeof(int *) * length)) == NULL)
    return;
  while (i < length)
    {
      if (((*res)[i] = malloc(sizeof(int) * width)) == NULL)
	return;
      while (j < width)
	{
	  (*res)[i][j] = tab[k];
	  j++;
	  k++;
	}
      i++;
      j = 0;
    }
}
