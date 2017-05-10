/*
** init_team.c for init_delay in /home/doghri_f/rendu/Zappy/Server/Sources
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Thu Jun 18 18:45:40 2015 Fares Doghri
** Last update Sun Jul  5 23:32:10 2015 Fares Doghri
*/

#include	"server.h"

/*
** Setter for team_name
*/

int		set_team(t_param *p, char **argv, int nbteam, int i)
{
  int		team;

  team = 0;
  if (nbteam < 2)
    {
      fprintf(stderr, "You need to put at least two teams\n");
      return (-1);
    }
  if ((p->team_name = malloc(sizeof(char *) * nbteam + 1)) == NULL)
    return -1;
  while (argv[i] && nbteam != 0)
    {
      p->team_name[team] = argv[i];
      ++team;
      ++i;
      --nbteam;
    }
  p->team_name[team] = NULL;
  return (0);
}

/*
** checker for team_name
*/

e_bool		check_team(t_param *p, char **argv, int i, t_option *op)
{
  int		nbteam;
  int		save;

  save = i;
  nbteam = 0;
  if (!strcmp(argv[i - 1], "-n"))
    {
      while (argv[i] && argv[i][0] != '-')
	{
	  ++nbteam;
	  ++i;
	}
      if (set_team(p, argv, nbteam, save) == -1)
	return (FALSE);
    }
  else
    {
      fprintf(stderr, "Usage : ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      fprintf(stderr, "-c [CLIENTS_MAX PER TEAM] -n [TEAM_1] [TEAM_2]... ");
      fprintf(stderr, "-t [TEMPORAL IN SECONDS]\n");
      return (FALSE);
    }
  op->n += 1;
  return (TRUE);
}
