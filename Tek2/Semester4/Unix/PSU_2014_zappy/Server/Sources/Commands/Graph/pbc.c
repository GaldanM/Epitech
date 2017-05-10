/*
** pbc.c for pbc in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:25:46 2015 Fares Doghri
** Last update Sun Jul  5 23:26:08 2015 Fares Doghri
*/

#include "server.h"

void 			pbc(t_param *p, int id, int id_p)
{
  char 		*cmd;
  t_player 	*tmp;

  if (!(tmp = get_player_by_id(p, id_p)))
    return ;
  if (asprintf(&cmd, "pbc %d %s\n", tmp->id, p->cmds[1]) == -1)
    return ;
  dprintf(id, "%s", cmd);
}
