/*
** init_options.c for init_optn in /home/doghri_f/rendu/Zappy/Server/Sources
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Fri Jun 19 17:39:57 2015 Fares Doghri
** Last update Fri Jun 19 18:39:50 2015 Fares Doghri
*/

#include	"server.h"

void		init_option(t_option *op)
{
  op->p = 0;
  op->x = 0;
  op->y = 0;
  op->c = 0;
  op->t = 0;
  op->n = 0;
}

e_bool		check_value_option(t_option *op)
{
  if (op->p == 0
      || op->x == 0
      || op->y == 0
      || op->c == 0
      || op->t == 0
      || op->n == 0)
    {
      fprintf(stderr, "Some options are not setted.\n");
      return FALSE;
    }
  if (op->p  > 1
      || op->x > 1
      || op->y > 1
      || op->c > 1
      || op->t > 1
      || op->n > 1)
    {
      fprintf(stderr, "Some options are setted more than once.\n");
      return FALSE;
    }
  return TRUE;
}
