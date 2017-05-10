/*
** fork.c for fork in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:21:47 2015 Fares Doghri
** Last update Sun Jul  5 23:22:18 2015 Fares Doghri
*/

#include	"server.h"

void		push_fork(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp)
    push_action(&(tmp->actions), my_fork, 42/p->delay, p->cmds);
}

void		my_fork(t_param *p, t_player *tmp)
{
  t_egg	src;

  if (tmp)
    {
      src.y = tmp->y;
      src.x = tmp->x;
      src.team = strdup(tmp->team);
      src.id_player = tmp->id;
      src.time = 300/p->delay * 1000000;
      if (push_egg(&(p->eggs), &src) == TRUE)
	dprintf(tmp->id, "ok\n");
    }
}
