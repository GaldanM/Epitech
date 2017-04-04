/*
** draw_line.c for FDF in /home/moulin_c/rendu/Modules/Igraph/TP_2
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Nov 14 10:53:13 2013 moulin_c
** Last update Sat Dec  7 17:09:48 2013 moulin_c
*/

#include "draw.h"

void	my_put_pixel_to_image(int x, int y, t_param *var, void *img_ptr)
{
  int	a;

  a = ((y * var->size_line) + (x * 4));
  var->data[a] = 255;
  a++;
  var->data[a] = 255;
  a++;
  var->data[a] = 255;
  a++;
  var->data[a] = 0;
}

void	draw_line(t_param *var)
{  
  draw_cas_un(var);
  draw_cas_cinq(var);
}

void	draw_cas_un(t_param *var)
{
  int	x;
  int	y;

  x = var->x1;
  if (x < var->x2) // CAS 1-2
    while (x < var->x2)
      {
	y = var->y1 + ((var->y2 - var->y1) * (x - var->x1)) / (var->x2 - var->x1);
	my_put_pixel_to_image(x, y, var, var->img_ptr);
	x = x + 1;
      }
  else if (x > var->x2) // CAS 3-4
    while (x > var->x2)
      {
	y = var->y1 + ((var->y2 - var->y1) * (x - var->x1)) / (var->x2 - var->x1);
	my_put_pixel_to_image(x, y, var, var->img_ptr);
	x = x - 1;
      }
}

void	draw_cas_cinq(t_param *var)
{
  int	x;
  int	y;

  y = var->y1;
  if (y < var->y2) // CAS 5-6
    while (y < var->y2)
      {
	x = var->x1 + ((var->x2 - var->x1) * (y - var->y1)) / (var->y2 - var->y1);
	my_put_pixel_to_image(x, y, var, var->img_ptr);
	y = y + 1;
      }
  else if (y > var->y2) // CAS 7-8
    while (y > var->y2)
      {
	x = var->x1 + ((var->x2 - var->x1) * (y - var->y1)) / (var->y2 - var->y1);
	my_put_pixel_to_image(x, y, var, var->img_ptr);
	y = y - 1;
      }
}
