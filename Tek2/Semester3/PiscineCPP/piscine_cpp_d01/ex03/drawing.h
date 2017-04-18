/*
** drawing.h for drawing in /home/moulin_c/rendu/piscine_cpp_d01/ex03
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  7 19:52:20 2015 Galdan MOULINNEUF
** Last update Wed Jan  7 20:28:11 2015 Galdan MOULINNEUF
*/

#ifndef DRAWING_H_
# define DRAWING_H_

#include	<stdint.h>
#include	<stdlib.h>

typedef struct __attribute__((packed))	s_point
{
  unsigned int	x;
  unsigned int	y;
}t_point;

void	draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color);

#endif /* DRAWING_H_ */
