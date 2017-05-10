/*
** expulse.c for expulse in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:19:48 2015 Fares Doghri
** Last update Sun Jul  5 23:20:00 2015 Fares Doghri
*/

#include 	"server.h"

void		push_expulse(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp && check_expulse(p, tmp) == TRUE)
    push_action(&(tmp->actions), expulse, 7/p->delay, p->cmds);
}

e_bool		check_expulse(t_param *p, t_player *tmp)
{
  int			y;
  int			x;
  int			id;

  y = tmp->y;
  x = tmp->x;
  id = tmp->id;
  tmp = p->players->next;
  while (tmp)
    {
      if (tmp->y == y && tmp->x == x && tmp->id != id)
	return (TRUE);
    }
  return (FALSE);
}

void		expulse(t_param *p, t_player *tmp)
{
  if (tmp)
    expulse_all(p, tmp);
}

void		expulse_all(t_param *p, t_player *tmp)
{
  int			y;
  int			x;
  int 		id;
  int			flag;
  e_direction	dir;

  flag = init_expulse_param(tmp, &y, &x, &dir);
  id = tmp->id;
  tmp = p->players->next;
  while (tmp)
    {
      if (tmp->y == y && tmp->x == x && tmp->id != id)
	{
	  if (dir == N)
	    tmp->y -= 1 % p->size_y;
	  else if (dir == S)
	    tmp->y += 1 % p->size_y;
	  else if (dir == E)
	    tmp->x += 1 % p->size_x;
	  else
	    tmp->x -= 1 % p->size_x;
	  dprintf(tmp->id, "deplacement: %d\n", (dir - 2) % 4);
	  flag = 1;
	}
      tmp = tmp->next;
    }
  if (!tmp && !flag)
    dprintf(id, "ko\n");
  else
    dprintf(id, "ok\n");
}

int			init_expulse_param(t_player *tmp, int *y, int *x, e_direction *dir)
{
  *y = tmp->y;
  *x = tmp->x;
  *dir = tmp->direction;
  return (0);
}
