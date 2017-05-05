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

int		quit_channel(t_channel *channels, t_client *clients, int fd, char **cmds)
{
  t_channel	*src;
  t_client	*to_del;

  (void)cmds;
  if ((src = get_channel_from_client(channels, fd)) == NULL)
    {
      dprintf(fd, "You are are not connected to any channel\n");
      return (EXIT_FAIL);
    }
  to_del = get_client_from_fd(clients, fd);
  remove_client_from_channel(src, to_del);
  remove_channel_from_client(to_del, src);
  dprintf(fd, "You left %s\n", src->name);
  return (EXIT_SUCCESS);
}
