/*
** manage_eggs.c for manage_egg in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Exec
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:30:14 2015 Fares Doghri
** Last update Sun Jul  5 23:30:20 2015 Fares Doghri
*/

#include "server.h"

t_egg		*decrease_egg(t_param *p, t_egg *tmp)
{
  int 			elapsed;
  struct timeval 	stop;
  t_egg			*next;

  next = tmp;
  gettimeofday(&stop, NULL);
  elapsed = stop.tv_usec - tmp->start.tv_usec;
  tmp->start = stop;
  if (elapsed >= 0)
    tmp->time -= elapsed;
  if (tmp->time <= 0)
    {
      if (tmp->hatched == TRUE)
	{
	  --(p->clients_team[get_team_id(p->team_name, tmp->team)]);
	  next = ghost_death(p->eggs, tmp);
	}
      else
	hatching(p, tmp);
    }
  return (next);
}

t_egg		*ghost_death(t_egg *eggs, t_egg *tmp)
{
  t_egg	*next;

  next = tmp->next;
  delete_egg(&eggs, tmp->id);
  return (next);
}

void		hatching(t_param *p, t_egg *tmp)
{
  if (tmp)
    {
      ++(p->clients_team[get_team_id(p->team_name, tmp->team)]);
      tmp->hatched = TRUE;
      tmp->time = 126 * 1/p->delay * 1000000 * 10;
      gettimeofday(&tmp->start, NULL);
    }
}
