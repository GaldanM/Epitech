/*
** exec_server.c for exec_server in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Exec
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:30:00 2015 Fares Doghri
** Last update Sun Jul  5 23:30:07 2015 Fares Doghri
*/

#include	"server.h"

e_bool 		exec_server(t_param *p)
{
  char	error = 0;

  while (!error)
    {
      set_fds(p);
      if (select(p->fd_max + 1, &p->fd_read, NULL, NULL, &p->tv) == FALSE)
	error = 1;
      else
	{
	  if (check_fds(p) == FALSE)
	    return (FALSE);
	}
      decrease_times(p);
      browse_actions(p);
      usleep(1);
    }
  return (TRUE);
}

void		set_fds(t_param *p)
{
  int 	i;

  i = 0;
  FD_ZERO(&p->fd_read);
  while (i < MAX_FD)
    {
      if (p->fd_type[i] != FD_FREE)
	{
	  FD_SET(i, &p->fd_read);
	  p->fd_max = i;
	}
      ++i;
    }
}

e_bool		check_fds(t_param *p)
{
  int		i;

  i = 0;
  while (i < MAX_FD)
    {
      if (FD_ISSET(i, &p->fd_read))
	p->fct_read[i](p, i);
      ++i;
    }
  return (TRUE);
}
