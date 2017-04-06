/*
** main.c for main.c in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/raytracer
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Dec 31 18:39:31 2013 moulin_c
** Last update Sun Jan 12 14:03:03 2014 moulin_c
*/

#include <stdlib.h>
#include "wolf.h"

int	init_struct(t_param *var)
{
  var->lenght = 800;
  var->width = 600;
  var->x0 = 1.5;
  var->y0 = 1.5;
  var->a = 0;
  if ((var->init = mlx_init()) == NULL)
    return (-1);
  if ((var->win = mlx_new_window(var->init, var->lenght, var->width,
	"Wolf3D")) == 0)
    return (-1);
  if ((var->img = mlx_new_image(var->init, var->lenght, var->width)) == 0)
    return (-1);
}

  int		main(int argc, char **argv)
  {
    t_param	var;

    if (argc > 1 && argv[1])
      {
	if (init_struct(&var) == -1)
	  return (-1);
	if ((var.tab = get_tab_int(argv[1])) == NULL)
	  return (-1);
	my_calc(&var);
	mlx_do_key_autorepeaton(var.init);
	mlx_hook(var.win, 2, (1L<<0), gere_key, &var);
	mlx_expose_hook(var.win, gere_expose, &var);
	mlx_loop(var.init);
      }
  }
