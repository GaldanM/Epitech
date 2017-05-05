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

int		check_name(t_client *clients, char *name)
{
  t_client	*tmp;

  tmp = clients;
  while (tmp)
    {
      if (tmp->nick && !strcmp(tmp->nick, name))
	return (EXIT_FAIL);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int		change_nick(t_channel *channels, t_client *clients, int fd, char **cmds)
{
  t_client	*client_rename;

  (void)channels;
  if ((cmds[1] == NULL)
      || (strlen(cmds[1]) > 9))
    {
      dprintf(fd, "To rename, you must enter a nickname (9 char max)\n");
      return (EXIT_FAIL);
    }
  client_rename = get_client_from_fd(clients, fd);
  if (check_name(clients, cmds[1]) == EXIT_SUCCESS)
    {
      printf("%s renamed as %s\n", client_rename->nick, cmds[1]);
      if (client_rename != NULL)
	free(client_rename->nick);
      client_rename->nick = cmds[1];
    }
  else
    dprintf(fd, "\"%s\" already exists, choose another one please\n", cmds[1]);
  return (EXIT_SUCCESS);
}
