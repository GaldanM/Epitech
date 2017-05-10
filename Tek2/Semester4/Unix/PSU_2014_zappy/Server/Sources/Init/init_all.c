/*
** init_all.c for init_all in /home/doghri_f/rendu/Zappy
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Fri Jun 19 13:48:24 2015 Fares Doghri
** Last update Sun Jul  5 23:33:38 2015 Fares Doghri
*/

#include		"server.h"

e_bool			init_all(t_param *p, char **argv)
{
  t_option		op;

  init_option(&op);
  if (check_options(argv) == FALSE)
    return (FALSE);
  if (init_param(p, argv, &op) == FALSE
    || init_server(p) == FALSE
    || init_map(p) == FALSE
    || ((p->players = init_player_list()) == NULL)
    || ((p->eggs = init_eggs()) == NULL)
    || ((p->graphs = init_graph()) == NULL)
    || init_max_clients(p) == FALSE)
    return (FALSE);
  return (TRUE);
}

e_bool			init_server(t_param *p)
{
  int			fd_socket;
  struct sockaddr_in	sin;

  memset(p->fd_type, FD_FREE, MAX_FD);
  if ((fd_socket = socket(PF_INET, SOCK_STREAM, 0)) == FALSE)
  {
    printf("socket failed\n");
    return (FALSE);
  }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(p->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if ((bind(fd_socket, (struct sockaddr*)&sin, sizeof(sin)) == FALSE)
      || (listen(fd_socket, 42) == FALSE))
  {
    printf("bind or listen failed\n");
    return (FALSE);
  }
  p->fd_s = fd_socket;
  p->fd_type[fd_socket] = FD_SERVER;
  p->fct_read[fd_socket] = read_server;
  p->fct_write[fd_socket] = NULL;
  return (TRUE);
}

e_bool			init_map(t_param *p)
{
  int			y;
  int 			x;

  if ((p->map = malloc(sizeof(t_case **) * p->size_y)) == NULL)
    return (FALSE);
  y = 0;
  while (y < p->size_y)
    {
      if ((p->map[y] = malloc(sizeof(t_case *) * p->size_x)) == NULL)
	return (FALSE);
      x = 0;
      while (x < p->size_x)
	{
	  p->map[y][x] = init_case_list();
	  ++x;
	}
      ++y;
    }
  return (TRUE);
}

/*
** Setter for all parameters
*/
e_bool			init_param(t_param *p, char **argv, t_option *op)
{
  int			i;

  i = 0;
  while (argv[i])
    {
      if (!strcmp("-p", argv[i]))
	{
	  if (check_port(p, argv, i, op) == FALSE)
	    return (FALSE);
	}
      else if (!strcmp("-x", argv[i]))
	{
	  if (check_width(p, argv, i, op) == FALSE)
	    return (FALSE);
	}
      else if (!strcmp("-y", argv[i]))
	{
	  if (check_height(p, argv, i, op) == FALSE)
	    return (FALSE);
	}
      else if (!strcmp("-n", argv[i]))
	{
	  if (check_team(p, argv, i + 1, op) == FALSE)
	    return (FALSE);
	}
      else if (!strcmp("-c", argv[i]))
	{
	  if (check_players(p, argv, i, op) == FALSE)
	    return (FALSE);
	}
      else if (!strcmp("-t", argv[i]))
	{
	  if (check_delay(p, argv, i, op) == FALSE)
	    return (FALSE);
	}
      ++i;
    }
  if (check_value_option(op) == FALSE)
    return (FALSE);
  p->tv.tv_sec = 5;
  p->tv.tv_usec = 0;
  return (TRUE);
}

e_bool      init_max_clients(t_param *p)
{
  int       nbteam;

  nbteam = 0;
  while (p->team_name[nbteam])
    ++nbteam;
  if ((p->clients_team = malloc(sizeof(int) * nbteam + 1)) == NULL)
    return (FALSE);
  nbteam = 0;
  while (p->team_name[nbteam])
  {
    p->clients_team[nbteam] = p->clients_max;
    ++nbteam;
  }
  return (TRUE);
}
