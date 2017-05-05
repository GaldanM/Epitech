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

void		disp_msg(char **cmds, int fd, int i)
{
  while (cmds[i])
    dprintf(fd, "%s ", cmds[i++]);
}

int		msg_to_user(t_channel *channels, t_client *clients, int fd, char **cmds)
{
  t_channel	*chan;
  t_client	*src;
  t_client	*dest;

  if (cmds[1] == NULL || cmds[2] == NULL)
    {
      dprintf(fd, "Usage : /msg [USER] [MESSAGE]\n");
      return (EXIT_FAIL);
    }
  chan = get_channel_from_client(channels, fd);
  src = get_client_from_fd(clients, fd);
  if (chan->flag != CHANNEL)
    {
      dprintf(fd, "You must connect to a channel first\n");
      return (EXIT_FAIL);
    }
  if ((dest = get_client_from_nick(clients, cmds[1])) == NULL)
    {
      dprintf(fd, "%s does not exist on this channel\n", cmds[1]);
      return (EXIT_FAIL);
    }
  dprintf(dest->fd, "from %s: %s", src->nick, cmds[2]);
  disp_msg(cmds, dest->fd, 3);
  return (EXIT_SUCCESS);
}

int		msg_to_channel(t_channel *channels, t_client *clients, int fd, char **cmds)
{
  t_channel		*chan;
  t_client		*src;
  t_lclient		*client;

  if ((chan = get_channel_from_client(channels, fd)) == NULL)
    return (EXIT_FAIL);
  if (chan->flag != CHANNEL)
    {
      dprintf(fd, "You must connect to a channel first\n");
      return (EXIT_FAIL);
    }
  src = get_client_from_fd(clients, fd);
  client = chan->clients;
  while (client)
    {
      if (client->cl->fd != fd)
	{
	  dprintf(client->cl->fd, "[%s]: ", src->nick);
	  disp_msg(cmds, client->cl->fd, 0);
	  write(client->cl->fd, "\n", 1);
	}
      client = client->next;
    }
  return (EXIT_SUCCESS);
}
