/*
** edi.c for edi in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:25:36 2015 Fares Doghri
** Last update Sun Jul  5 23:26:18 2015 Fares Doghri
*/

#include "server.h"

void 			edi(t_param *p, int id, int id_p)
{
  t_egg 		*tmp;

  tmp = p->eggs->next;
  while (tmp && tmp->id_player != id_p)
    tmp = tmp->next;
  if (tmp)
    dprintf(id, "edi %d\n", tmp->id);
}
