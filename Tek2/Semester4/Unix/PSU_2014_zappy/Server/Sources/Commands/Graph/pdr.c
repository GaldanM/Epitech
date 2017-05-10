/*
** pdr.c for pdr in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:25:49 2015 Fares Doghri
** Last update Sun Jul  5 23:26:05 2015 Fares Doghri
*/

#include "server.h"

void 			pdr(t_param *p, int id, int id_p)
{
  dprintf(id, "pdr %d %s\n", id_p, p->cmds[1]);
}
