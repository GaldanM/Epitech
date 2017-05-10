/*
** init_height.c for init_height in /home/doghri_f/rendu/Zappy/Server/Sources
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Thu Jun 18 17:32:33 2015 Fares Doghri
** Last update Sun Jul  5 23:32:52 2015 Fares Doghri
*/

/*
** Setter for height
*/

#include	"server.h"

int		set_height(char *argv)
{
  int		i;

  i = 0;
  while (argv[i])
    {
      if (argv[i] < '0' || argv[i] > '9')
	{
	  fprintf(stderr, "Invalid height field.\nUsage : ");
	  fprintf(stderr, "-p [0->9] 5 <= height.\n");
	  return (-1);
	}
      ++i;
    }
  return (atoi(argv));
}

/*
** Checker for height
*/

e_bool		check_height(t_param *p, char **argv, int i, t_option *op)
{
  if (!strcmp(argv[i], "-y") && argv[i + 1])
    {
      if ((p->size_y = set_height(argv[i + 1])) < 1)
	{
	  fprintf(stderr, "The minimal value for your map's height is 1\n");
	  return (FALSE);
	}
    }
  else
    {
      fprintf(stderr, "Usage : ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      fprintf(stderr, "-c [CLIENTS_MAX PER TEAM] -t [TEMPORAL IN SECONDS] ");
      fprintf(stderr, "-n [TEAM_1] [TEAM_2]...\n");
      return (FALSE);
    }
  op->y += 1;
  return (TRUE);
}
