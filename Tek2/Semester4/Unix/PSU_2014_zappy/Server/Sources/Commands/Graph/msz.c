/*
** msz.c for msz in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:25:09 2015 Fares Doghri
** Last update Sun Jul  5 23:26:54 2015 Fares Doghri
*/

#include "server.h"

void 	msz(t_param *p, int id, int id_p)
{
  (void)id_p;
  dprintf(id, "msz %d %d\n", p->size_x, p->size_y);
}
