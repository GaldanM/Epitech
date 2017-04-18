/*
** drawing.c for drawing in /home/moulin_c/rendu/piscine_cpp_d01/ex03
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  7 19:58:18 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 08:30:13 2015 Galdan MOULINNEUF
*/

#include	"drawing.h"

void		draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color)
{
  int	x = 0;
  int	y = 0;

  while (y < size)
    {
      while (x < size)
	{
	  img[orig->y + y][orig->x + x] = color;
	  x++;
        }
      x = 0;
      y++;
    }
}
