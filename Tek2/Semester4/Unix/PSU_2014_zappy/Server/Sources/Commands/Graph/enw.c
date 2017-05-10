/*
** enw.c for enw in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:25:41 2015 Fares Doghri
** Last update Sun Jul  5 23:26:14 2015 Fares Doghri
*/

#include "server.h"

void 			enw(t_param *p, int id, int id_p)
{
  t_egg 		*tmp;

  tmp = p->eggs->next;
  while (tmp && tmp->id_player != id_p)
    tmp = tmp->next;
  if (tmp)
    dprintf(id, "enw %d %d %d %d\n", tmp->id, id_p, tmp->x, tmp->y);
}

void				enw_all(t_param *p, int id)
{
  t_player 	*tmp;

  tmp = p->players->next;
  while (tmp)
    {
      enw(p, id, tmp->id);
      tmp = tmp->next;
    }
}
