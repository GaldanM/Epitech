/*
** is_there_color.c for my_boogle in /home/sement_s/rendu/colle6_moulin_c_7TtAi
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon Jun  2 20:42:43 2014 Stephen SEMENT
** Last update Mon Jun  2 21:11:33 2014 Stephen SEMENT
*/

#include	<stdlib.h>
#include	"bparam.h"

int		is_there_color(char *av, t_param *param)
{
  if (my_strcmp(av, "--color") == 0)
    param->color = 1;
  return (0);
}

int		is_grid_valid(t_param *param)
{
  if (param->grid == NULL)
    return (0);
  if (my_strlen(param->grid) != (param->size * param->size))
    return (-1);
  return (0);
}
