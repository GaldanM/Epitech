/*
** init_delay.c for init_delay in /home/doghri_f/rendu/Zappy/Server/Sources
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Thu Jun 18 17:45:40 2015 Fares Doghri
** Last update Fri Jun 19 18:28:36 2015 Fares Doghri
*/

#include	"server.h"

/*
** Setter for delay
*/

int		set_delay(char *argv)
{
  int		i;

  i = 0;
  while (argv[i])
    {
      if (argv[i] < '0' || argv[i] > '9')
	{
	  fprintf(stderr, "Invalid delay field.\nUsage : ");
	  fprintf(stderr, "-p [0->9] 1 <= delay.\n");
	  return (-1);
	}
      ++i;
    }
  return atoi(argv);
}

/*
** Checker for delay
*/

e_bool		check_delay(t_param *p, char **argv, int i, t_option *op)
{
  if (!strcmp(argv[i], "-t") && argv[i + 1])
    {
      if ((p->delay = set_delay(argv[i + 1])) < 1)
	{
	  fprintf(stderr, "The setted time needs to be higher than 1.\n");
	  return FALSE;
	}
    }
  else
    {
      fprintf(stderr, "Usage : ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      fprintf(stderr, "-c [CLIENTS_MAX PER TEAM] -t [TEMPORAL IN SECONDS] ");
      fprintf(stderr, "-n [TEAM_1] [TEAM_2]...\n");
      return FALSE;
    }
  op->t += 1;
  return TRUE;
}
