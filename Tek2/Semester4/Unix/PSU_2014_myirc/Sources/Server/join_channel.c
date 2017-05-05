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

int		join_channel(t_channel *channels, t_client *clients, int fd, char **cmds)
{
  t_channel	*dest;
  t_client	*client;

  if (cmds[1] == NULL)
    {
      dprintf(fd, "You must enter a correct channel name\n");
      return (EXIT_FAIL);
    }
  if ((dest = get_channel_from_name(channels, cmds[1])) == NULL)
    if ((dest = add_channel(channels, cmds[1])) == NULL)
      return (EXIT_FAIL);
  client = get_client_from_fd(clients, fd);
  add_channel_to_client(dest, client);
  add_client_to_channel(client, dest);
  display_users(channels, clients, fd, cmds);
  printf("%s left his channel to join %s\n", client->nick, dest->name);
  return (EXIT_SUCCESS);
}
