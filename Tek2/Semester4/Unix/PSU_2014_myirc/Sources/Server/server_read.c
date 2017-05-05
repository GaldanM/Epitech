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

int			add_client(t_channel *channels, t_client **clients, int fd_c)
{
  t_lclient		*new;
  t_client		*new_cl;
  t_lchannel		*new_ch;

  if ((new_ch = init_lchannel(channels)) == NULL)
    return (EXIT_FAIL);
  if ((new_cl = init_client(fd_c, new_ch)) == NULL)
    return (EXIT_FAIL);
  if ((new = init_lclient(new_cl)) == NULL)
    return (EXIT_FAIL);
  put_lcl_channel(new, channels);
  put_cl_to_cl(new_cl, clients);
  return (EXIT_SUCCESS);
}

int			set_env(t_env *e, int fd_s)
{
  int			fd_c;
  struct sockaddr_in	sin;
  socklen_t		len;

  len = sizeof(sin);
  if ((fd_c = accept(fd_s, (struct sockaddr *)&sin, &len)) == -1)
    return (EXIT_FAIL);
  e->fd_type[fd_c] = FD_CLIENT;
  e->fct_read[fd_c] = client_read;
  e->fct_write[fd_c] = NULL;
  return (fd_c);
}

t_client		*server_read(t_channel *chs, t_client *cls, t_env *e, int fd_s)
{
  int			fd_c;

  if (((fd_c = set_env(e, fd_s)) == EXIT_FAIL)
      || (add_client(chs, &cls, fd_c) == EXIT_FAIL))
    return (NULL);
  printf("New client\n");
  return (cls);
}
