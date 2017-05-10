/*
** pnw.c for pnw in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:24:03 2015 Fares Doghri
** Last update Sun Jul  5 23:24:06 2015 Fares Doghri
*/

#include "server.h"

void 			pnw_all(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players->next;
  while (tmp)
    {
      pnw(p, id, tmp->id);
      tmp = tmp->next;
    }
}

void 			pnw(t_param *p, int id, int id_p)
{
  char 		*cmd;
  t_player	*tmp;

  cmd = NULL;
  if (!(tmp = get_player_by_id(p, id_p)))
    return ;
  if (asprintf(&cmd, "pnw %d %d %d %d %d %s\n", tmp->id, tmp->x, tmp->y,
	       tmp->direction + 1, tmp->lvl, tmp->team) == -1)
    return ;
  dprintf(id, "%s", cmd);
}
