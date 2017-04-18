/*
** menger.c for menger in /home/moulin_c/rendu/piscine_cpp_d01/ex01
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  7 13:05:41 2015 Galdan MOULINNEUF
** Last update Wed Jan  7 13:31:50 2015 Galdan MOULINNEUF
*/

#include	<stdio.h>

void		menger(int size, int depth, int x, int y)
{
  int		coor_x;
  int		coor_y;

  if (size % 3 == 0)
    {
      size = size / 3;
      depth--;
      coor_x = size + x;
      coor_y = size + y;
      printf("%03d %03d %03d\n", size, coor_x, coor_y);
      if (depth > 0)
	{
	  menger(size, depth, x, y);
	  menger(size, depth, x, y + size);
	  menger(size, depth, x, y + 2 * size);
	  menger(size, depth, x + size, y);
	  menger(size, depth, x + size, y + 2 * size);
	  menger(size, depth, x + 2 * size, y);
	  menger(size, depth, x + 2 * size, y + size);
	  menger(size, depth, x + 2 * size, y + 2 * size);
	}
    }
}
