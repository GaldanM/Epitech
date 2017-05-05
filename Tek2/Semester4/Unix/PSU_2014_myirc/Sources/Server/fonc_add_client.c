/*
** for  in /home/moulin_c/rendu/NewIRC/IRC/Sources/Server
**
** Made by MOULINNEUF Galdan
** Login   <moulin_c@epitech.net>
**
** Started on  Sat Apr 11 14:22:13 2015 MOULINNEUF Galdan
** Last update Sun Apr 12 22:50:46 2015 MOULINNEUF Galdan
*/

#include "server.h"

t_lchannel	*init_lchannel(t_channel *channels)
{
  t_lchannel	*new_ch;

  if ((new_ch = malloc(sizeof(t_lchannel))) == NULL)
    return (NULL);
  new_ch->ch = channels;
  new_ch->next = NULL;
  return (new_ch);
}

t_client	*init_client(int fd_c, t_lchannel *new_ch)
{
  t_client	*new_cl;

  if ((new_cl = malloc(sizeof(t_client))) == NULL)
    return (NULL);
  new_cl->fd = fd_c;
  new_cl->nick = NULL;
  new_cl->next = NULL;
  new_cl->channels = new_ch;
  return (new_cl);
}

t_lclient	*init_lclient(t_client *new_cl)
{
  t_lclient	*new;

  if ((new = malloc(sizeof(t_lclient))) == NULL)
    return (NULL);
  new->cl = new_cl;
  new->next = NULL;
  return (new);
}

void		put_lcl_channel(t_lclient *new, t_channel *channels)
{
  t_lclient	*tmp;

  tmp = channels->clients;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (tmp)
    tmp->next = new;
  else
    channels->clients = new;
}

void		put_cl_to_cl(t_client *new_cl, t_client **clients)
{
  t_client	*tmp2;

  tmp2 = *clients;
  while (tmp2 && tmp2->next)
    tmp2 = tmp2->next;
  if (tmp2)
    tmp2->next = new_cl;
  else
    *clients = new_cl;
}
