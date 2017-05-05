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

int		display_users(t_channel *channels, t_client *clients, int fd, char **cmds)
{
  t_channel	*tmp;
  t_lclient	*tmp2;

  (void)cmds;
  (void)clients;
  tmp = get_channel_from_client(channels, fd);
  if (tmp)
    {
      dprintf(fd, "Liste des utilisateurs sur le channel %s :\n", tmp->name);
      tmp2 = tmp->clients;
      while (tmp2)
	{
	  dprintf(fd, "\t\t%s\n", tmp2->cl->nick);
	  tmp2 = tmp2->next;
	}
      return (EXIT_SUCCESS);
    }
  else
    dprintf(fd, "Connect to a channel first\n");
  return (EXIT_FAIL);
}

int		display_channels(t_channel *chs, t_client *cls, int fd, char **cmds)
{
  char		*cmp;
  t_channel	*tmp;

  (void)cls;
  cmp = cmds[1];
  tmp = chs;
  while (tmp)
    {
      if (tmp->flag == CHANNEL)
	{
	  dprintf(fd, "Liste des channels disponibles :\n");
	  if (cmp == NULL || (!strncmp(tmp->name, cmp, strlen(cmp))))
	    dprintf(fd, "\t\t%s\n", tmp->name);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
