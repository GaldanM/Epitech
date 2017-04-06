/*
** zooms.c for wolf in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/raytracer
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Jan  7 18:18:57 2014 moulin_c
** Last update Sun Jan 12 14:52:49 2014 moulin_c
*/

#include "wolf.h"

void	transl_up(t_param *var)
{
  var->x0 = var->x0 + (cos(RAD(var->a)) / 10);
  var->y0 = var->y0 + (sin(RAD(var->a)) / 10);
  if (var->tab[(int)var->y0][(int)var->x0] == 1)
    {
      var->x0 = var->x0 - (cos(RAD(var->a)) / 10);
      var->y0 = var->y0 - (sin(RAD(var->a)) / 10);
    }
  my_calc(var);
  mlx_put_image_to_window(var->init, var->win, var->img, 0, 0);
}

void	transl_down(t_param *var)
{
  var->x0 = var->x0 - (cos(RAD(var->a)) / 10);
  var->y0 = var->y0 - (sin(RAD(var->a)) / 10);
  if (var->tab[(int)var->y0][(int)var->x0] == 1)
    {
      var->x0 = var->x0 + (cos(RAD(var->a)) / 10);
      var->y0 = var->y0 + (sin(RAD(var->a)) / 10);
    }
  my_calc(var);
  mlx_put_image_to_window(var->init, var->win, var->img, 0, 0);
}

void	rotate_left(t_param *var)
{
  if (var->a + 10 <= 360)
    var->a = var->a + 10;
  else
    var->a = var->a - 360;
  my_calc(var);
  mlx_put_image_to_window(var->init, var->win, var->img, 0, 0);
}

void	rotate_right(t_param *var)
{
  if (var->a - 10 >= 0)
    var->a = var->a - 10;
  else
    var->a = 360 - 10;
  my_calc(var);
  mlx_put_image_to_window(var->init, var->win, var->img, 0, 0);
}
