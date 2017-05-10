/*
** put_object.c for put_object in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:22:44 2015 Fares Doghri
** Last update Sun Jul  5 23:22:52 2015 Fares Doghri
*/

# include "server.h"

void		push_put_object(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp && check_put_object(p, tmp) == TRUE)
    push_action(&(tmp->actions), put_object, 7/p->delay, p->cmds);
}

e_bool		check_put_object(t_param *p, t_player *tmp)
{
  int 	i;
  char 	*res[12] = {"nourriture", "linemate",
		    "deraumere", "sibur", "mendiane",
		    "phiras", "thystame"};

  i = 0;
  while (res[i] && p->cmds[1])
    {
      if (!strcmp(res[i], p->cmds[1]))
	{
	  if (tmp->inventory[i] > 0)
	    return (TRUE);
	}
      ++i;
    }
  return (FALSE);
}

void		put_object(t_param *p, t_player *tmp)
{
  int 		i;
  char 		*res[12] = {"nourriture", "linemate",
			    "deraumere", "sibur", "mendiane",
			    "phiras", "thystame"};

  if (tmp)
    {
      i = 0;
      while (res[i] && p->cmds[1])
	{
	  if (!strcmp(res[i], p->cmds[1]))
	    {
	      put_in_map(p, tmp, i);
	      return ;
	    }
	  ++i;
	}
    }
  printf("Client[%d]: Unknown ressource to put!\n", tmp->id);
  dprintf(tmp->id, "ko\n");
}

void		put_in_map(t_param *p, t_player *tmp, int ressource)
{
  if (tmp->inventory[ressource] > 0)
    {
      push_ressource(&p->map[tmp->y][tmp->x], ressource);
      --(tmp->inventory[ressource]);
      printf("Client[%d]: Put ressource in [%d][%d] !\n", tmp->id, tmp->y, tmp->x);
      dprintf(tmp->id, "ok\n");
    }
  else
    {
      printf("Client[%d]: Client does have that ressource !\n", tmp->id);
      dprintf(tmp->id, "ko\n");
    }
}
