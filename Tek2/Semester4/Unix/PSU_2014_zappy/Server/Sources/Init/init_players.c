/*
** init_players.c for ini_players in /home/doghri_f/rendu/Zappy/Server/Sources
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Thu Jun 18 17:39:05 2015 Fares Doghri
** Last update Sun Jul  5 23:32:31 2015 Fares Doghri
*/

#include		"server.h"

/*
** Setter for clients_max
*/

int			set_players(char *argv)
{
  int			i;

  i = 0;
  while (argv[i])
    {
      if (argv[i] < '0' || argv[i] > '9')
	{
	  fprintf(stderr, "Invalid client_max per team field.\nUsage : ");
	  fprintf(stderr, "-c [0->9] 1 <= client_max per team.\n");
	  return (-1);
	}
      ++i;
    }
  return (atoi(argv));
}

/*
** Checker for clients_max
*/

e_bool			check_players(t_param *p, char **argv, int i, t_option *op)
{
  if (!strcmp(argv[i], "-c") && argv[i + 1])
    {
      if ((p->clients_max = set_players(argv[i + 1])) < 1)
	{
	  fprintf(stderr, "You need at least 1 client for your teams.\n");
	  return (FALSE);
	}
    }
  else
    {
      fprintf(stderr, "Usage : ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      fprintf(stderr, "-c [CLIENTS_MAX PER TEAM] -n [TEAM_1] [TEAM_2]... ");
      fprintf(stderr, "-t [TEMPORAL IN SECONDS]\n");
      return (FALSE);
    }
  op->c += 1;
  return (TRUE);
}
