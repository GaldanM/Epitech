/*
** check_options.c for check_options in /home/doghri_f/rendu/Zappy/Server/Sources
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Fri Jun 19 16:13:56 2015 Fares Doghri
** Last update Fri Jun 19 18:29:43 2015 Fares Doghri
*/

#include	"server.h"

e_bool		not_option(char *argv)
{
  char		*option[6] = {"-p", "-x", "-y", "-c", "-t", "-n"};
  int		i;

  i = 0;
  while (option[i])
    {
      if (strcmp(argv, option[i]) == 0)
	return TRUE;
      ++i;
    }
  if (i == 6)
    {
      fprintf(stderr, "%s is not a possible option for the server.\n", argv);
      return FALSE;
    }
  return TRUE;
}

e_bool		check_options(char **argv)
{
  int		i;
  int		flag;

  i = 0;
  flag = 0;
  while (argv[i])
    {
      if (argv[i][0] == '-')
	{
	  if (not_option(argv[i]) == FALSE)
	    return FALSE;
	  ++flag;
	}
      ++i;
    }
  if (flag != 6)
    {
      fprintf(stderr, "Usage : ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      fprintf(stderr, "-c [CLIENTS_MAX PER TEAM] -n [TEAM_1] [TEAM_2]... ");
      fprintf(stderr, "-t [TEMPORAL IN SECONDS]\n");
      return FALSE;
    }
  return TRUE;
}
