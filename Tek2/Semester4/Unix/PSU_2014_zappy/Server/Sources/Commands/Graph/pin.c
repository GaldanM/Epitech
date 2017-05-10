/*
** pin.c for pin in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:24:09 2015 Fares Doghri
** Last update Sun Jul  5 23:24:11 2015 Fares Doghri
*/

#include "server.h"

void 			pin(t_param *p, int id, int id_p)
{
  char 		*cmd;
  t_player 	*tmp;
  int 		a;
  int 		b;
  int 		c;
  int 		d;
  int 		e;

  if (!(tmp = get_player_by_id(p, id_p)))
    return ;
  a = tmp->inventory[0];
  b = tmp->inventory[1];
  c = tmp->inventory[2];
  d = tmp->inventory[3];
  e = tmp->inventory[4];
  if (asprintf(&cmd, "pin %d %d %d %d %d %d %d %d", 
	       id_p, tmp->x, tmp->y, a, b, c, d, e) == -1)
    return ;
  a = tmp->inventory[5];
  b = tmp->inventory[6];
  if (asprintf(&cmd, "%s %d %d\n", cmd, a, b) == -1)
    return ;
  dprintf(id, "%s", cmd);
}
