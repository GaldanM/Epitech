/*
** bct_map.c for bct_map in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:25:32 2015 Fares Doghri
** Last update Sun Jul  5 23:26:20 2015 Fares Doghri
*/

#include "server.h"

void 		bct_map(t_param *p, int id, int id_p)
{
  char	*str;
  char	*cmd;
  int 	x;
  int 	y;

  (void)id_p;
  y = 0;
  cmd = "";
  while (y < p->size_y)
    {
      x = 0;
      while (x < p->size_x)
	{
	  if ((str = get_case(p, x, y)) == NULL
	      || asprintf(&cmd, "%s%s", cmd, str) == -1)
	    return ;
	  ++x;
	}
      ++y;
    }
  dprintf(id, "%s", cmd);
}
