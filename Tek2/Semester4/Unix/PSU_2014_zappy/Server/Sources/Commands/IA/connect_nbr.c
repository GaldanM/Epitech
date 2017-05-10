/*
** connect_nbr.c for connect_nbr in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:21:37 2015 Fares Doghri
** Last update Sun Jul  5 23:21:44 2015 Fares Doghri
*/

#include 		"server.h"

void		push_connect_nbr(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  push_action(&(tmp->actions), connect_nbr, 0, p->cmds);
}

void			connect_nbr(t_param *p, t_player *tmp)
{
  int 		i;
  int 		no_used;

  if (tmp)
    {
      i = 0;
      while (p->team_name[i] && strcmp(p->team_name[i], tmp->team))
	++i;
      if (p->team_name[i])
	{
	  no_used = p->clients_team[i] - count_in_team(p, tmp->team);
	  dprintf(tmp->id, "%d\n", no_used);
	}
    }
}

int 			count_in_team(t_param *p, char *team)
{
  int 		nb;
  t_player	*tmp;

  nb = 0;
  tmp = p->players->next;
  while (tmp)
    {
      if (!strcmp(tmp->team, team))
	++nb;
      tmp = tmp->next;
    }
  return (nb);
}
