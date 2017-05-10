/*
** sgt.c for sgt in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:23:35 2015 Fares Doghri
** Last update Sun Jul  5 23:23:48 2015 Fares Doghri
*/

#include "server.h"

void 	sgt_send(t_param *p, int id, int id_p)
{
  (void)id_p;
  dprintf(id, "sgt %d\n", p->delay);
}

void 	sgt_set(t_param *p, int id)
{
  p->delay = atoi(p->cmds[1]);
  if (p->delay < 1)
    p->delay = 1;
  dprintf(id, "sgt %d\n", p->delay);
}
