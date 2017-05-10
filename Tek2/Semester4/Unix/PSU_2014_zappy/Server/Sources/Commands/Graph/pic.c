/*
** pic.c for pic in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:24:16 2015 Fares Doghri
** Last update Sun Jul  5 23:24:17 2015 Fares Doghri
*/

#include "server.h"

void 			pic(t_param *p, int id, int id_p)
{
  char 		*cmd;
  t_player 	*tmp;
  int 		x;
  int 		y;

  if (!(tmp = get_player_by_id(p, id_p)))
    return ;
  x = tmp->x;
  y = tmp->y;
  if (asprintf(&cmd, "pic %d %d %d", tmp->x, tmp->y, tmp->lvl) == -1)
    return ;
  tmp = p->players->next;
  while (tmp)
    {
      if (tmp->x == x && tmp->y == y)
	if (asprintf(&cmd, "%s %d", cmd, tmp->id) == -1)
	  return ;
      tmp = tmp->next;
    }
  dprintf(id, "%s\n", cmd);
}
