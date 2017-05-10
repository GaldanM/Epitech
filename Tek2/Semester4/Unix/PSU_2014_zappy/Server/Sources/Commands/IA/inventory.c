/*
** inventory.c for inventory in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:22:38 2015 Fares Doghri
** Last update Sun Jul  5 23:22:39 2015 Fares Doghri
*/

# include "server.h"

void		push_inventory(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp)
    push_action(&(tmp->actions), inventory, 1/p->delay, p->cmds);
}

void		inventory(t_param *p, t_player *tmp)
{
  char		*str;

  (void)p;
  str = NULL;
  if (tmp)
    {
      asprintf(&str, "{nourriture %d, linemate %d, deraumere %d",
	       tmp->inventory[0], tmp->inventory[1], tmp->inventory[2]);
      dprintf(tmp->id, "%s, sibur %d, mendiane %d, phiras %d, thystame %d}\n",
	      str, tmp->inventory[3], tmp->inventory[4],
	      tmp->inventory[5], tmp->inventory[6]);
      free(str);
    }
}
