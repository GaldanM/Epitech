/*
** for  in /home/moulin_c/rendu/NewIRC/IRC/Sources/Server
**
** Made by MOULINNEUF Galdan
** Login   <moulin_c@epitech.net>
**
** Started on  Sat Apr 11 14:22:13 2015 MOULINNEUF Galdan
** Last update Sun Apr 12 22:50:46 2015 MOULINNEUF Galdan
*/

#include	"server.h"

t_channel	*init_channel()
{
  t_channel	*server;
  t_lclient	*new;

  if ((server = malloc(sizeof(t_channel))) == NULL)
    return (NULL);
  if ((new = malloc(sizeof(t_lclient))) == NULL)
    return (NULL);
  new->cl = NULL;
  new->next = NULL;
  server->name = strdup("connected");
  server->clients = new;
  server->flag = NO_CHANNEL;
  server->next = NULL;
  return (server);
}

t_channel	*add_channel(t_channel *channels, char *name)
{
  t_channel	*tmp;
  t_channel	*new;
  t_lclient	*new_cl;

  if ((new = malloc(sizeof(t_channel))) == NULL)
    return (NULL);
  if ((new_cl = malloc(sizeof(t_lclient))) == NULL)
    return (NULL);
  new_cl->cl = NULL;
  new_cl->next = NULL;
  new->name = name;
  new->clients = new_cl;
  new->flag = CHANNEL;
  new->next = NULL;
  tmp = channels;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  return (new);
}

void		remove_channel(t_channel *channels, t_channel *to_del)
{
  t_channel	*tmp;

  tmp = channels;
  while (tmp->next != to_del)
    tmp = tmp->next;
  tmp->next = to_del->next;
  free(to_del->name);
  free(to_del);
}
