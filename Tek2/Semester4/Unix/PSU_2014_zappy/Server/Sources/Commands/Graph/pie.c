/*
** pie.c for pie in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:24:53 2015 Fares Doghri
** Last update Sun Jul  5 23:27:03 2015 Fares Doghri
*/

#include "server.h"

void 	pie(t_param *p, int id, int r)
{
  dprintf(id, "msz %d %d %d\n", p->size_x, p->size_y, r);
}
