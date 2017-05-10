/*
** init_port.c for init_port in /home/doghri_f/rendu/Zappy/Server/Sources
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Thu Jun 18 17:21:00 2015 Fares Doghri
** Last update Fri Jun 19 18:26:09 2015 Fares Doghri
*/

#include	"server.h"

/*
** Setter for port
*/

int		set_port(char *argv)
{
  int		i;

  i = 0;
  while (argv[i])
    {
      if (argv[i] < '0' || argv[i] > '9')
	{
	  fprintf(stderr, "Invalid port field.\nUsage : ");
	  fprintf(stderr, "-p [0->9] 1024 <= port <= 65535.\n");
	  return (-1);
	}
      ++i;
    }
  return atoi(argv);
}

/*
** checker for port
*/

e_bool		check_port(t_param *p, char **argv, int i, t_option *op)
{
  if (!strcmp(argv[i], "-p") && argv[i + 1])
    {
      if ((p->port = set_port(argv[i + 1])) <= 1023)
	{
	  if (p->port > 65535)
	    {
	      fprintf(stderr, "Your port is higher than 65 535.\n");
	      return FALSE;
	    }
	  fprintf(stderr, "Your port is lower than 1023, root access needed.");
	  return FALSE;
	}
    }
  else
    {
      fprintf(stderr, "Usage : ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      fprintf(stderr, "-c [CLIENTS_MAX PER TEAM] -n [TEAM_1] [TEAM_2]... ");
      fprintf(stderr, "-t [TEMPORAL IN SECONDS]\n");
      return FALSE;
    }
  op->p += 1;
  return TRUE;
}
