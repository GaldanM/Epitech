/*
** pgt.c for pgt in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:24:57 2015 Fares Doghri
** Last update Sun Jul  5 23:27:01 2015 Fares Doghri
*/

#include "server.h"

void 			pgt(t_param *p, int id, int id_p)
{
  dprintf(id, "pgt %d %s\n", id_p, p->cmds[1]);
}
