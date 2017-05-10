/*
** look.c for look in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:17:55 2015 Fares Doghri
** Last update Sun Jul  5 23:18:40 2015 Fares Doghri
*/

# include 		"server.h"

void		push_look(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp)
    push_action(&(tmp->actions), look, (double)7/p->delay, p->cmds);
}

void			look(t_param *p, t_player *tmp)
{
  char		*send;

  if (!tmp)
    return;
  if (tmp->direction == N)
    {
      if ((send = vision_north(p, tmp)) == NULL)
	return;
    }
  else if (tmp->direction == E)
    {
      if ((send = vision_east(p, tmp)) == NULL)
	return;
    }
  else if (tmp->direction == O)
    {
      if ((send = vision_west(p, tmp)) == NULL)
	return;
    }
  else
    {
      if ((send = vision_south(p, tmp)) == NULL)
	return;
    }
  dprintf(tmp->id, "%s\n", send);
  free(send);
}

char			*vision_north(t_param *p, t_player *tmp)
{
  char			*send;
  t_p_look		pa;

  pa.r_y = 1;
  pa.r_x = 0;
  pa.p = p;
  pa.tmp = tmp;
  pa.r_max = tmp->lvl * 2 + 1;
  pa.y = tmp->y;
  if ((send = malloc(1)) == NULL)
    return (NULL);
  send[0] = 0;
  if (((send = my_strcat(send, "{")) == NULL)
      || ((send = browse_north(&pa, send)) == NULL)
      || ((send = my_strcat(send, "}")) == NULL))
    return (NULL);
  return (send);
}

char			*vision_east(t_param *p, t_player *tmp)
{
  char			*send;
  t_p_look		pa;

  pa.r_y = 0;
  pa.r_x = 1;
  pa.p = p;
  pa.tmp = tmp;
  pa.r_max = tmp->lvl * 2 + 1;
  pa.x = tmp->x;
  if ((send = malloc(1)) == NULL)
    return (NULL);
  send[0] = 0;
  if (((send = my_strcat(send, "{")) == NULL)
      || ((send = browse_east(&pa, send)) == NULL)
      || ((send = my_strcat(send, "}")) == NULL))
    return (NULL);
  return (send);
}

char			*vision_west(t_param *p, t_player *tmp)
{
  char			*send;
  t_p_look		pa;

  pa.r_y = 0;
  pa.r_x = 1;
  pa.p = p;
  pa.tmp = tmp;
  pa.r_max = tmp->lvl * 2 + 1;
  pa.x = tmp->x;
  if ((send = malloc(1)) == NULL)
    return (NULL);
  send[0] = 0;
  if (((send = my_strcat(send, "{")) == NULL)
      || ((send = browse_west(&pa, send)) == NULL)
      || ((send = my_strcat(send, "}")) == NULL))
    return (NULL);
  return (send);
}

char			*vision_south(t_param *p, t_player *tmp)
{
  char			*send;
  t_p_look		pa;

  pa.r_y = 1;
  pa.r_x = 0;
  pa.p = p;
  pa.tmp = tmp;
  pa.r_max = tmp->lvl * 2 + 1;
  pa.y = tmp->y;
  if ((send = malloc(1)) == NULL)
    return (NULL);
  send[0] = 0;
  if (((send = my_strcat(send, "{")) == NULL)
      || ((send = browse_south(&pa, send)) == NULL)
      || ((send = my_strcat(send, "}")) == NULL))
    return (NULL);
  return (send);
}
