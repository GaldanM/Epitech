/*
** fdf.c for fdf in /home/moulin_c/rendu/Modules/Igraph/TP_tpfdf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Dec  6 19:18:40 2013 moulin_c
** Last update Sat Dec  7 17:10:09 2013 moulin_c
*/

#include "draw.h"

int	gere_expose(t_param *var)
{
  mlx_put_image_to_window(var->init_ptr, var->win_ptr, var->img_ptr, 0, 0);
}


int	gere_key(int keycode, t_param *var)
{
  if (keycode == 65307)
    exit(1);
  return (0);
}

void	trace_x(t_param var)
{
  int	a;
  int	i;

  a  = 50;
  i = 0;
  proj_iso(0, 0, 0, &var);
  var.x1 = var.x;
  var.y1 = var.y;
  proj_iso(a, 0, 0, &var);
  var.x2 = var.x;
  var.y2 = var.y;
  while (i < 3)
    {
      a = a + 50;
      draw_line(&var);
      var.x1 = var.x2;
      var.y1 = var.y2;
      proj_iso(a, 0, 0, &var);
      var.x2 = var.x;
      var.y2 = var.y;
      i++;
    }
}

void	trace_y(t_param var)
{
  int	a;
  int	i;

  a = 50;
  i = 0;
  proj_iso(0, 0, 0, &var);
  var.x1 = var.x;
  var.y1 = var.y;
  proj_iso(0, a, 0, &var);
  var.x2 = var.x;
  var.y2 = var.y;
  while (i < 3)
    {
      a = a + 50;
      draw_line(&var);
      var.x1 = var.x2;
      var.y1 = var.y2;
      proj_iso(0, a, 0, &var);
      var.x2 = var.x;
      var.y2 = var.y;
      i++;
    }
}

int	main()
{
  t_param	var;

  var.init_ptr = mlx_init();
  var.win_ptr = mlx_new_window(var.init_ptr, 1000, 700, "Draw");
  var.img_ptr = mlx_new_image(var.init_ptr, 1000, 700);
  var.data = mlx_get_data_addr(var.img_ptr, &var.bpp, &var.size_line, &var.endian);
  trace_x(var);
  trace_y(var);
  mlx_key_hook(var.win_ptr, gere_key, &var);
  mlx_expose_hook(var.win_ptr, gere_expose, &var);
  mlx_loop(var.init_ptr);
  return (0);
}
