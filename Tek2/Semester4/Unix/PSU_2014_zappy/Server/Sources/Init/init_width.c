/*
** init_width.c for init_width in /home/doghri_f/rendu/Zappy/Server/Sources
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Thu Jun 18 17:21:58 2015 Fares Doghri
** Last update Sun Jul  5 23:31:46 2015 Fares Doghri
*/

#include		"server.h"

/*
** Setter for size_x
*/

int			set_width(char *argv)
{
  int			i;

  i = 0;
  while (argv[i])
    {
      if (argv[i] < '0' || argv[i] > '9')
	{
	  fprintf(stderr, "Invalid width field.\nUsage : ");
	  fprintf(stderr, "-x [0->9] 5 <= width.\n");
	  return (-1);
	}
      ++i;
    }
  return (atoi(argv));
}

/*
** Checker for size_x
*/

e_bool			check_width(t_param *p, char **argv, int i, t_option *op)
{
  if (!strcmp(argv[i], "-x") && argv[i + 1])
    {
      if ((p->size_x = set_width(argv[i + 1])) < 1)
	{
	  fprintf(stderr, "The minimal value for your map's width is 1\n");
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
  op->x += 1;
  return (TRUE);
}
