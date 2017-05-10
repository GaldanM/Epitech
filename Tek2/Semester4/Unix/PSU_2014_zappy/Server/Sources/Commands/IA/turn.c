/*
** turn.c for turn.c in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:15:33 2015 Fares Doghri
** Last update Sun Jul  5 23:15:52 2015 Fares Doghri
*/

#include	"server.h"

void		push_right(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp)
    push_action(&(tmp->actions), right, 7/p->delay, p->cmds);
}

void		right(t_param *p, t_player *tmp)
{
  (void)p;
  if (tmp)
    {
      (tmp->direction)++;
      if (tmp->direction > O)
	tmp->direction = N;
      dprintf(tmp->id, "ok\n");
      set_sound(tmp, 1);
      /*if (tmp->direction == N)
	printf("Le player [%d] est désormais orienté vers le Nord !\n", id);

	else if (tmp->direction == E)
	printf("Le player [%d] est désormais orienté vers l'Est !\n", id);

	else if (tmp->direction == S)
	printf("Le player [%d] est désormais orienté vers le Sud!\n", id);

	else if (tmp->direction == O)
	printf("Le player [%d] est désormais orienté vers l'Ouest !\n", id);
      */
    }
}

void		push_left(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp)
    push_action(&(tmp->actions), left, 7/p->delay, p->cmds);
}

void		left(t_param *p, t_player *tmp)
{
  (void)p;
  if (tmp)
    {
      (tmp->direction)--;
      if ((int)tmp->direction < N)
	tmp->direction = O;
      dprintf(tmp->id, "ok\n");
      set_sound(tmp, 2);
      /*if (tmp->direction == N)
	printf("Le player [%d] est désormais orienté vers le Nord !\n", id);

	else if (tmp->direction == E)
	printf("Le player [%d] est désormais orienté vers l'Est !\n", id);

	else if (tmp->direction == S)
	printf("Le player [%d] est désormais orienté vers le Sud!\n", id);

	else if (tmp->direction == O)
	printf("Le player [%d] est désormais orienté vers l'Ouest !\n", id);
      */
    }
}

void		set_sound(t_player *tmp, int turn)
{
  int		i;

  i = 0;
  while (turn == 1 && i < 8)
    {
      tmp->sound[i] += 2;
      if (tmp->sound[i] > 8)
	tmp->sound[i] -= 8;
      ++i;
    }
  while (turn == 2 && i < 8)
    {
      tmp->sound[i] -= 2;
      if (tmp->sound[i] < 0)
	tmp->sound[i] += 8;
      ++i;
    }
}
