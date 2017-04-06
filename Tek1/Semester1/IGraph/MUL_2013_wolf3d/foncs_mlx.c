/*
** foncs_mlx.c for foncs in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/raytracer
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  1 17:55:37 2014 moulin_c
** Last update Sun Jan 12 01:40:39 2014 moulin_c
*/

#include <stdlib.h>
#include "wolf.h"

int		gere_expose(t_param *var)
{
  mlx_put_image_to_window(var->init, var->win, var->img, 0, 0);
}

int             gere_key(int keycode, t_param *var)
{
  if (keycode == 65362)
      transl_up(var);
  if (keycode == 65364)
      transl_down(var);
  if (keycode == 65361)
    rotate_left(var);
  if (keycode == 65363)
    rotate_right(var);
  if (keycode == 65307)
    exit(1);
}

void	get_rgb(t_param *var)
{
  var->r = (var->color >> 16) & 255;
  var->g = (var->color >> 8) & 255;
  var->b = var->color & 255;
}

void	my_put_pixel_to_image(t_param *var)
{
  char	*data;
  int	a;
  int	endian;
  int	bpp;
  int	size_line;

  data = mlx_get_data_addr(var->img, &bpp, &size_line, &endian);
  a = ((var->y * size_line) + (var->x * 4));
  get_rgb(var);
  data[a++] = var->b;
  data[a++] = var->g;
  data[a++] = var->r;
  data[a] = 0;
}
