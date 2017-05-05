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

void		remove_client_from_channel(t_channel *channel, t_client *client)
{
  t_lclient	*tmp;

  tmp = channel->clients;
  while (tmp && tmp->next->cl != client)
    tmp = tmp->next;
  if (tmp)
    tmp->next = tmp->next->next;
  else
    channel->clients = channel->clients->next;
}

void		remove_channel_from_client(t_client *client, t_channel *channel)
{
  t_lchannel	*tmp;

  tmp = client->channels;
  while (tmp && tmp->next->ch != channel)
    tmp = tmp->next;
  if (tmp)
    tmp->next = tmp->next->next;
  else
    client->channels = client->channels->next;
}

int		add_client_to_channel(t_client *client, t_channel *dest)
{
  t_lchannel	*tmp;
  t_lchannel	*new;

  if ((new = malloc(sizeof(t_lchannel))) == NULL)
    return (EXIT_FAIL);
  new->ch = dest;
  new->next = NULL;
  tmp = client->channels;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (tmp)
    tmp->next = new;
  else
    tmp = new;
  return (EXIT_SUCCESS);
}

int		add_channel_to_client(t_channel *dest, t_client *client)
{
  t_lclient	*tmp;
  t_lclient	*new;

  if ((new = malloc(sizeof(t_lclient))) == NULL)
    return (EXIT_FAIL);
  new->cl = client;
  new->next = NULL;
  tmp = dest->clients;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (tmp)
    tmp->next = new;
  else
    tmp = new;
  return (EXIT_SUCCESS);
}
