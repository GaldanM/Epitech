/*
** smg.c for smg in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:24:29 2015 Fares Doghri
** Last update Sun Jul  5 23:27:18 2015 Fares Doghri
*/

#include "server.h"

void 			smg(t_param *p, int id, int id_p)
{
  (void)id_p;
  dprintf(id, "smg %s\n", p->cmds[1]);
}
