/*
** display_wolf.c for wolf3 in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/raytracer
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  8 19:22:41 2014 moulin_c
** Last update Sun Jan 12 01:40:48 2014 moulin_c
*/

#include "wolf.h"

void	my_wall(t_param *var)
{
  var->color = 0; // BLCK
  var->x = var->x1;
  var->y = var->pos_top;
  my_put_pixel_to_image(var);
  var->color = 0x706F6D; // GREY
  var->y1 = var->pos_top + 1;
  var->y2 = var->pos_bot;
  draw_line(var);
  var->color = 0; // BLCK
  var->x = var->x1;
  var->y = var->pos_bot;
  my_put_pixel_to_image(var);
}

void	my_wolf(t_param *var, int i)
{
  var->x1 = i;
  var->x2 = var->x1;
  var->color = 0x3A9EEA; //BLUE
  var->y1 = 0;
  var->y2 = var->pos_top;
  draw_line(var);
  my_wall(var);
  var->color = 0x059105;  // GREEN
  var->y1 = var->pos_bot + 1;
  var->y2 = var->width;
  draw_line(var);
}
