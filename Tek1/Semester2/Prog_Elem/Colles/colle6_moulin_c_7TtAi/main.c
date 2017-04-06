/*
** main.c for my_boogle in /home/sement_s/rendu/colle6_moulin_c_7TtAi
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon Jun  2 19:10:27 2014 Stephen SEMENT
** Last update Mon Jun  2 21:00:01 2014 Stephen SEMENT
*/

#include <stdlib.h>
#include "bparam.h"

int		main(int ac, char **av)
{
  t_param	param;

  if (ac > 8)
    {
      my_putstr("Usage : ./my_boogle [-s SIZE] [-g GRID] [-w WORD] --color\n");
      return (-1);
    }
  else
    {
      init_params(&param);
      if (check_params(ac, av, &param) == -1)
	{
	  my_putstr("Wrong parameters. Please refer to the README.\n");
	  return (-1);
	}
      if (is_grid_valid(&param) == -1)
	{
	  my_putstr("Bad grid size.\n");
	  return (-1);
	}
      printf("%d\n", param.color);
    }
  return (0);
}
