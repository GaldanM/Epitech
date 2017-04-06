/*
** draw_line.c for FDF in /home/moulin_c/rendu/Modules/Igraph/TP_2
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Nov 14 10:53:13 2013 moulin_c
** Last update Sun Jan 12 01:43:04 2014 moulin_c
*/

#include "wolf.h"

void	draw_cas_un(t_param *var)
{
  int	calc;

  var->x = var->x1;
  if (var->x < var->x2)
    {
      calc = ((var->y2 - var->y1) * (var->x - var->x1)) / (var->x2 - var->x1);
      while (var->x < var->x2)
	{
	  var->y = var->y1 + calc;
	  my_put_pixel_to_image(var);
	  var->x++;
	}
    }
  else if (var->x > var->x2)
    {
      calc = ((var->y2 - var->y1) * (var->x - var->x1)) / (var->x2 - var->x1);
      while (var->x > var->x2)
	{
	  var->y = var->y1 + calc;
	  my_put_pixel_to_image(var);
	  var->x--;
	}
    }
}

void	draw_cas_cinq(t_param *var)
{
  int	calc;

  var->y = var->y1;
  if (var->y < var->y2)
    {
      calc = ((var->x2 - var->x1) * (var->y - var->y1)) / (var->y2 - var->y1);
      while (var->y < var->y2)
	{
	  var->x = var->x1 + calc;
	  my_put_pixel_to_image(var);
	  var->y++;
	}
    }
  else if (var->y > var->y2)
    {
      calc = ((var->x2 - var->x1) * (var->y - var->y1)) / (var->y2 - var->y1);
      while (var->y > var->y2)
	{
	  var->x = var->x1 + calc;
	  my_put_pixel_to_image(var);
	  var->y--;
	}
    }
}

void	draw_line(t_param *var)
{
  draw_cas_un(var);
  draw_cas_cinq(var);
}
