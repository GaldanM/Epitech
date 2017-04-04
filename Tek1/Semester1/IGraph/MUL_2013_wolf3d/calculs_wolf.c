/*
** calculs_wolf.c for wolf3d in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/raytracer
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  8 19:21:52 2014 moulin_c
** Last update Sun Jan 12 01:44:49 2014 moulin_c
*/

#include "wolf.h"

void	calc_vector(t_param *var, int i)
{
  var->x1 = var->d;
  var->y1 = ((var->p * (var->lenght / 2) - i) / var->lenght);
  var->x2 = (var->x1 * cos(var->a_rad)) - (var->y1 * sin(var->a_rad));
  var->y2 = (var->x1 * sin(var->a_rad)) + (var->y1 * cos(var->a_rad));
  var->x1 = var->x2 + var->x0;
  var->y1 = var->y2 + var->y0;
  var->vx = (var->x1 - var->x0);
  var->vy = (var->y1 - var->y0);
}

void	calc_k(t_param *var)
{
  var->k = 1;
  var->x = var->x0 + (var->k * var->vx);
  var->y = var->y0 + (var->k * var->vy);
  while (var->tab[var->y][var->x] == 0)
    {
      var->k = var->k + 0.005;
      var->x = var->x0 + (var->k * var->vx);
      var->y = var->y0 + (var->k * var->vy);
    }
}

void	calc_size(t_param *var)
{
  var->size = ((var->width) / var->k);
  var->pos_top = (var->width / 2) - (var->size / 2);
  var->pos_bot = (var->width / 2) + (var->size / 2);
}

void	my_calc(t_param *var)
{
  int	i;

  i = 0;
  var->a_rad = ((var->a / 180) * M_PI);
  var->p = 1;
  var->d = 0.5;
  while (i < var->lenght)
    {
      calc_vector(var, i);
      calc_k(var);
      calc_size(var);
      my_wolf(var, i);
      i++;
    }
}
