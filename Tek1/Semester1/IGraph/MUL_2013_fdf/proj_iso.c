/*
** proj_iso.c for tptpfdf in /home/moulin_c/rendu/Modules/Igraph/TP_tpfdf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec  5 19:47:22 2013 moulin_c
** Last update Sat Dec  7 17:12:52 2013 moulin_c
*/

#include "draw.h"

void	proj_iso(int x, int y, int z, t_param *var)
{

  var->x = 0.5 * x - 0.5 * y;
  var->y = z + (0.5 / 2) * x + (0.5 / 2) * y;
  var->x = var->x + 500;
  var->y = var->y + 350;
}
