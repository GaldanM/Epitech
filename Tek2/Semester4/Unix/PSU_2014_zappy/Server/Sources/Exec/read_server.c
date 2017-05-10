/*
** read_server.c for read_server in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Exec
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:28:22 2015 Fares Doghri
** Last update Sun Jul  5 23:28:28 2015 Fares Doghri
*/

#include				"server.h"

e_bool					read_server(t_param *p, int fd_s)
{
  int					fd_c;
  socklen_t			len;
  struct sockaddr_in	sin;

  len = sizeof(sin);
  if ((fd_c = accept(fd_s, (struct sockaddr *)&sin, &len)) == FALSE)
    {
      fprintf(stderr, "Accept failed\n");
      return (FALSE);
    }
  printf("New client [%d] has just connected !\n", fd_c);
  dprintf(fd_c, "BIENVENUE\n");
  p->fd_type[fd_c] = FD_CLIENT;
  p->fct_read[fd_c] = read_client;
  p->fct_write[fd_c]  = NULL;
  return (TRUE);
}
