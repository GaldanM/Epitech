/*
** take_object.c for take_object in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:16:22 2015 Fares Doghri
** Last update Sun Jul  5 23:17:25 2015 Fares Doghri
*/

# include "server.h"

void		push_take_object(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp)
    push_action(&(tmp->actions), take_object, 7/p->delay, p->cmds);
}

e_bool		check_take_object(t_param *p, t_player *tmp)
{
  int		i;
  char		*res[12] = {"nourriture", "linemate",
		    "deraumere", "sibur", "mendiane",
		    "phiras", "thystame"};

  i = 0;
  while (res[i] && p->cmds[1])
    {
      if (!strcmp(res[i], p->cmds[1]))
	{
	  if (check_ressource(p->map[tmp->y][tmp->x], i) == TRUE)
	    return (TRUE);
	}
      ++i;
    }
  return (FALSE);
}

void		take_object(t_param *p, t_player *tmp)
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
	      take_it(p, tmp, i);
	      return ;
	    }
	  ++i;
	}
    }
  printf("Client[%d]: Unknown ressource to take!\n", tmp->id);
  dprintf(tmp->id, "ko\n");
}

void		take_it(t_param *p, t_player *tmp, int ressource)
{
  int		y;
  int		x;

  if (check_ressource(p->map[tmp->y][tmp->x], ressource) == TRUE)
    {
      printf("Client[%d]: Take ressource in [%d][%d] !\n", tmp->id, tmp->y, tmp->x);
      delete_ressource(&(p->map[tmp->y][tmp->x]), ressource);
      ++(tmp->inventory[ressource]);
      srand(time(NULL));
      y = rand() % p->size_y;
      x = rand() % p->size_x;
      push_ressource(&(p->map[y][x]), ressource);
      dprintf(tmp->id, "ok\n");
    }
  else
    {
      printf("Client[%d]: Ressource not available !\n", tmp->id);
      dprintf(tmp->id, "ko\n");
    }
}
