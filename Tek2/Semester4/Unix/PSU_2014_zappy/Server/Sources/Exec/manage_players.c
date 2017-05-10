/*
** manage_players.c for manage_players in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Exec
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:30:30 2015 Fares Doghri
** Last update Sun Jul  5 23:30:39 2015 Fares Doghri
*/

#include "server.h"

t_player		*decrease_food_player(t_param *p, t_player *tmp)
{
  int 			elapsed;
  struct timeval 	stop;
  t_player		*next;

  next = tmp;
  gettimeofday(&stop, NULL);
  elapsed = stop.tv_usec - tmp->start.tv_usec;
  tmp->start = stop;
  if (elapsed >= 0)
    tmp->time -= elapsed;
  if (tmp->time <= 0)
    {
      --(tmp->inventory[NOURRITURE]);
      tmp->time = 1000000 * 126 * 1/p->delay;
    }
  if (tmp->inventory[NOURRITURE] < 0)
    next = player_death(p, tmp);
  return (next);
}

t_player		*player_death(t_param *p, t_player *tmp)
{
  t_player	*next;

  next = p->players->next;
  dprintf(tmp->id, "mort\n");
  p->fd_type[tmp->id] = FD_FREE;
  close(tmp->id);
  if (tmp->status == GHOST)
    --(p->clients_team[get_team_id(p->team_name, tmp->team)]);
  delete_player(&(p->players), tmp->id);
  return (next);
}

void		decrease_actions_player(t_player *tmp1)
{
  int				elapsed;
  struct timeval	stop;
  t_action 		*tmp2;

  tmp2 = tmp1->actions->next;
  if (tmp2)
    {
      gettimeofday(&stop, NULL);
      elapsed = stop.tv_usec - tmp2->start.tv_usec;
      tmp2->start = stop;
      if (elapsed >= 0)
	tmp2->time -= elapsed;
    }
}

void		browse_actions_player(t_param *p, t_player *tmp1)
{
  t_action		*tmp2;

  tmp2 = tmp1->actions->next;
  if (tmp2 && tmp2->time <= 0)
    {
      (tmp2->fct)(p, tmp1);
      delete_action(&(tmp1->actions));
    }
}
