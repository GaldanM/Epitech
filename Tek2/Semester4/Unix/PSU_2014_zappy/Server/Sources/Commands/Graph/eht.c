/*
** eht.c for eht in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:25:13 2015 Fares Doghri
** Last update Sun Jul  5 23:26:51 2015 Fares Doghri
*/

#include "server.h"

void 			eht(t_param *p, int id, int id_p)
{
  t_egg 		*tmp;

  tmp = p->eggs->next;
  while (tmp && tmp->id_player != id_p)
    tmp = tmp->next;
  if (tmp)
    dprintf(id, "eht %d\n", tmp->id);
}
