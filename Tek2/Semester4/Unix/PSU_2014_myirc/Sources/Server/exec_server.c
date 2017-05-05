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

void			set_fd(t_param *p)
{
  int			i;

  FD_ZERO(&p->fd_read);
  p->fd_max = 0;
  i = 0;
  while (i < MAX_FD)
    {
      if (p->e.fd_type[i] != FD_FREE)
	{
	  FD_SET(i, &p->fd_read);
	  p->fd_max = i;
	}
      ++i;
    }
}

t_client		*check_fds(t_param *p, t_channel *channels, t_client *clients)
{
  int			i;

  i = 0;
  while (i < MAX_FD)
    {
      if (FD_ISSET(i, &p->fd_read))
	if ((clients = p->e.fct_read[i](channels, clients, &p->e, i)) == NULL)
	  return (NULL);
      ++i;
    }
  return (clients);
}

int			server_exec(t_param *p, t_channel *channels, t_client *clients)
{
  while (1)
    {
      set_fd(p);
      if (select(p->fd_max + 1, &p->fd_read, NULL, NULL, &p->tv) == -1)
	perror("select");
      if ((clients = check_fds(p, channels, clients)) == NULL)
	return (EXIT_FAIL);
    }
  return (EXIT_SUCCESS);
}
