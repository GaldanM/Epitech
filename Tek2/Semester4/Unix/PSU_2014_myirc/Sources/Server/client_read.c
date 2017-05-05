/*
** for  in /home/moulin_c/rendu/NewIRC/IRC/Sources/Server
**
** Made by MOULINNEUF Galdan
** Login   <moulin_c@epitech.net>
**
** Started on  Sat Apr 11 14:22:13 2015 MOULINNEUF Galdan
** Last update Sun Apr 12 22:50:46 2015 MOULINNEUF Galdan
*/

#include		"server.h"

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  while (i < 8)
    free(tab[i++]);
  free(tab);
}

char			**create_tab_cmd()
{
  char			**cmd;

  if ((cmd = malloc(8 * sizeof(char *))) == NULL)
    return (NULL);
  if (!(cmd[0] = strdup("/nick"))
      || (!(cmd[1] = strdup("/list")))
      || (!(cmd[2] = strdup("/join")))
      || (!(cmd[3] = strdup("/part")))
      || (!(cmd[4] = strdup("/users")))
      || (!(cmd[5] = strdup("/send_file")))
      || (!(cmd[6] = strdup("/accept_file")))
      || (!(cmd[7] = strdup("/msg"))))
    return (NULL);
  return (cmd);
}

void			*search_func(char **tab, char **cmds)
{
  int			i;
  int			(*func[9])(t_channel *, t_client *,  int, char **);

  func[0] = &change_nick;
  func[1] = &display_channels;
  func[2] = &join_channel;
  func[3] = &quit_channel;
  func[4] = &display_users;
  func[7] = &msg_to_user;
  func[8] = &msg_to_channel;
  i = 0;
  while (i < 8)
    {
      if (!strcmp(tab[i], cmds[0]))
	{
	  free_tab(tab);
	  return (func[i]);
	}
      ++i;
    }
  free_tab(tab);
  if (cmds[0][0] == '/')
    return (NULL);
  return (func[8]);
}

int			exec_cmd(t_channel *channels, t_client *clients, int fd, char **cmds)
{
  int			(*func)();
  char			**tab;

  if (((tab = create_tab_cmd()) == NULL)
      || (cmds[0] == NULL)
      || ((func = (int (*)())search_func(tab, cmds)) == NULL))
    {
      dprintf(fd, "\"%s\" is not a correct command\n", cmds[0]);
      return (EXIT_FAIL);
    }
  (*func)(channels, clients, fd, cmds);
  return (EXIT_SUCCESS);
}

t_client		*client_read(t_channel *channels, t_client *clients, t_env *e, int fd)
{
  int			r;
  char			buf[4096 + 1];
  char			**tab;

  (void)e;
  r = read(fd, buf, 4096);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      if ((tab = str_to_tab(buf)) == NULL)
	return (NULL);
      if (exec_cmd(channels, clients, fd, tab) == EXIT_FAIL)
	return (NULL);
      return (clients);
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      if (close(fd) == -1)
	return (NULL);
      e->fd_type[fd] = FD_FREE;
    }
  return (clients);
}
