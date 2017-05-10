/*
** forward.c for forward$ in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:19:21 2015 Fares Doghri
** Last update Sun Jul  5 23:19:38 2015 Fares Doghri
*/

#include	"server.h"

void		push_forward(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp)
    push_action(&(tmp->actions), forward, 7/p->delay, p->cmds);
}

void		forward(t_param *p, t_player *tmp)
{
  if (tmp)
    {
      if (tmp->direction == N)
	go_north(p, tmp);
      else if (tmp->direction == E)
	go_east(p, tmp);
      else if (tmp->direction == O)
	go_west(p, tmp);
      else
	go_south(p, tmp);
      dprintf(tmp->id, "ok\n");
      printf("Le player [%d] est désormais à la case [%d][%d] !\n", tmp->id, tmp->y, tmp->x);
    }
}

void		go_north(t_param *p, t_player *tmp)
{
  (tmp->y)--;
  if (tmp->y < 0)
    tmp->y = p->size_y - 1;
}

void		go_east(t_param *p, t_player *tmp)
{
  (tmp->x)++;
  if (tmp->x == p->size_x)
    tmp->x = 0;
}

void		go_west(t_param *p, t_player *tmp)
{
  (tmp->x)--;
  if (tmp->x < 0)
    tmp->x = p->size_x - 1;
}

void		go_south(t_param *p, t_player *tmp)
{
  (tmp->y)++;
  if (tmp->y == p->size_y)
    tmp->y = 0;
}
