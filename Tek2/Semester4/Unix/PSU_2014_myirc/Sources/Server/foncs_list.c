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

t_client	*get_client_from_fd(t_client *clients, int fd)
{
  t_client	*tmp;

  tmp = clients;
  while (tmp)
    {
      if (tmp->fd == fd)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_client	*get_client_from_nick(t_client *clients, char *name)
{
  t_client	*tmp;

  tmp = clients;
  while (tmp)
    {
      if (!strcmp(tmp->nick, name))
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_channel	*get_channel_from_client(t_channel *channels, int fd)
{
  t_channel	*tmp;
  t_lclient	*tmp2;

  tmp = channels->next;
  while (tmp)
    {
      tmp2 = tmp->clients;
      while (tmp2)
	{
	  if (tmp2->cl && tmp2->cl->fd == fd)
	    return (tmp);
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_channel	*get_channel_from_name(t_channel *channels, char *name)
{
  t_channel	*tmp;

  tmp = channels->next;
  while (tmp)
    {
      if (!strcmp(tmp->name, name))
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
