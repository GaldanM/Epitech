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

int			add_server(t_env *e)
{
  int			s;
  struct sockaddr_in	sin;

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (EXIT_FAIL);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if ((bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
      || (listen(s, 42) == -1))
    return (EXIT_FAIL);
  e->fd_type[s] = FD_SERVER;
  e->fct_read[s] = server_read;
  e->fct_write[s] = NULL;
  return (EXIT_SUCCESS);
}

int			init_server(t_param *p, char *port)
{
  memset(p->e.fd_type, FD_FREE, MAX_FD);
  p->e.port = atoi(port);
  p->tv.tv_sec = 2000;
  p->tv.tv_usec = 0;
  return (add_server(&p->e));
}
