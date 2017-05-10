/*
** my_square_root.c for my_square_root in /home/moulin_c/rendu/A check
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct 11 16:01:13 2013 moulin_c
** Last update Fri Apr 18 04:23:12 2014 moulin_c
*/

#include "my.h"

int	my_square_root(int nb)
{
  int	square;

  square = 0;
  while (square * square <=  nb)
    {
      if (square * square == nb)
	return (square);
      square++;
    }
  return (0);
}
