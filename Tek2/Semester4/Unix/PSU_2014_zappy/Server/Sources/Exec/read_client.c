/*
** read_client.c for READ_CLIENT in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Exec
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:28:54 2015 Fares Doghri
** Last update Sun Jul  5 23:29:22 2015 Fares Doghri
*/

#include	"server.h"

e_bool          read_client(t_param *p, int fd_c)
{
  int         ret;
  char        *buff;

  if ((buff = get_next_line(fd_c, &ret)) == NULL && ret < 1)
    {
      p->fd_type[fd_c] = FD_FREE;
      close(fd_c);
      fprintf(stderr, "Client is no longer available\n");
      return (FALSE);
    }
  if (!strcmp(buff, "GRAPHIC") && connect_graphic(p, fd_c) == FALSE)
    {
      p->fd_type[fd_c] = FD_FREE;
      close(fd_c);
    }
  else if (strcmp(buff, "GRAPHIC") && connect_ia(p, buff, fd_c) == FALSE)
    {
      p->fd_type[fd_c] = FD_FREE;
      close(fd_c);
    }
  return (TRUE);
}

e_bool          connect_graphic(t_param *p, int fd_c)
{
  (void)p;
  start_graph(p, fd_c);
  if (push_graph(&(p->graphs), fd_c) == FALSE)
    return (FALSE);
  p->fd_type[fd_c] = FD_GRAPH;
  p->fct_read[fd_c] = read_graph;
  p->fct_write[fd_c]  = NULL;
  return (TRUE);
}

void            start_graph(t_param *p, int id)
{
  msz(p, id, 0);
  sgt_send(p, id, 0);
  bct_map(p, id, 0);
  tna(p, id, 0);
  pnw_all(p, id);
  enw_all(p, id);
}

e_bool          connect_ia(t_param *p, char *team, int fd_c)
{
  t_player      player;

  srand(time(NULL));
  if (check_team_exist(p, team, fd_c) == FALSE)
    return (FALSE);
  if (check_ghosts(p, team) == TRUE)
    return (connect_ghost(p, team, fd_c));
  printf("Je cree un PLAYER ! \n");
  player.y = rand() % p->size_y;
  player.x = rand() % p->size_x;
  player.id = fd_c;
  player.status = PLAYER;
  player.time = 1000000 * 126 * 1/p->delay;
  if ((player.team = strdup(team)) == NULL)
    return (FALSE);
  if (push_player(&p->players, &player) == FALSE)
    return (FALSE);
  p->fd_type[fd_c] = FD_IA;
  p->fct_read[fd_c] = read_ia;
  p->fct_write[fd_c]  = NULL;
  return (TRUE);
}

void            spawn_ressources(t_param *p)
{
  int           y;
  int           x;
  int           nb;
  e_ressource   i;

  srand(time(NULL));
  i = 0;
  while (i < 7)
    {
      nb = 0;
      while (nb < 12)
	{
	  y = rand() % p->size_y;
	  x = rand() % p->size_x;
	  push_ressource(&(p->map[y][x]), i);
	  ++nb;
	}
      ++i;
    }
}

e_bool          check_ghosts(t_param *p, char *team)
{
  t_egg           *tmp;

  tmp = p->eggs->next;
  while (tmp)
    {
      if (tmp->hatched == TRUE && !strcmp(team, tmp->team))
	return (TRUE);
      tmp = tmp->next;
    }
  return (FALSE);
}

e_bool          connect_ghost(t_param *p, char *team, int fd_c)
{
  t_player        player;
  t_egg           *tmp;

  tmp = p->eggs->next;
  while (tmp)
    {
      if (tmp->hatched == TRUE && !strcmp(team, tmp->team))
	{
	  player.y = tmp->y;
	  player.x = tmp->x;
	  player.id = fd_c;
	  player.status = GHOST;
	  player.time = 1000000 * 126 * 1/p->delay;
	  if ((player.team = strdup(team)) == NULL)
	    return (FALSE);
	  if (push_player(&p->players, &player) == FALSE)
	    return (FALSE);
	  delete_egg(&(p->eggs), tmp->id);
	  p->fd_type[fd_c] = FD_IA;
	  p->fct_read[fd_c] = read_ia;
	  p->fct_write[fd_c]  = NULL;
	  return (TRUE);
	}
      tmp = tmp->next;
    }
  return (FALSE);
}

e_bool          check_team_exist(t_param *p, char *team, int fd_c)
{
  int         i;

  i = 0;
  while (p->team_name[i])
    {
      if (!strcmp(p->team_name[i], team))
	{
	  if (nb_player_team(p, team, fd_c) == FALSE)
	    {
	      fprintf(stderr, "Client[%d] left: Team is full\n", fd_c);
	      return (FALSE);
	    }
	  printf("Client[%d] has join Team : %s\n", fd_c, team);
	  dprintf(fd_c, "%d %d\n", p->size_x, p->size_y);
	  return (TRUE);
	}
      ++i;
    }
  dprintf(fd_c, "ko\n");
  fprintf(stderr, "Client[%d] left: Team doesn't exist\n", fd_c);
  return (FALSE);
}

e_bool          nb_player_team(t_param *p, char *team, int fd_c)
{
  int           i;
  int           nb;
  t_player      *tmp;

  nb = 1;
  tmp = p->players->next;
  while (tmp)
    {
      if (!strcmp(team, tmp->team))
	++nb;
      tmp = tmp->next;
    }
  i = 0;
  while (p->team_name[i] && strcmp(p->team_name[i], team))
    ++i;
  if (p->clients_team[i] - nb >= 0)
    {
      dprintf(fd_c, "%d\n", p->clients_team[i] - nb);
      return (TRUE);
    }
  dprintf(fd_c, "ko\n");
  return (FALSE);
}
