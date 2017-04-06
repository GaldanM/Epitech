/*
** args.c for my_mastermind in /home/sement_s/rendu/colle2_moulin_c/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May  5 20:38:54 2014 Stephen SEMENT
** Last update Mon May  5 22:20:29 2014 moulin_c
*/

#include	<stdlib.h>
#include	"my.h"

int		arg_slots(char *av, t_param *param)
{
  if (verif_int(av) == -1 || av[0] == '\0')
    my_exitstr("Argument after -s must be a number.\n", -1);
  param->slot = my_atoi(av);
  return (0);
}

int		arg_try(char *av, t_param *param)
{
  if (verif_int(av) == -1 || av[0] == '\0')
    my_exitstr("Argument after -t must be a positive number.\n", -1);
  param->try = my_atoi(av);
  if (param->try < 1)
    my_exitstr("Try must be strictly positive\n");
  return (0);
}

int		default_pions(t_param *param)
{
  int		i;

  i = 0;
  if ((param->pions = malloc(sizeof(char) * 9)) == NULL)
    my_exitstr("Malloc error, program must close.\n", -1);
  while (i < 8)
    {
      param->pions[i] = i + 48;
      i = i + 1;
    }
  param->pions[8] = '\0';
  return (0);
}

int		arg_pions(char *av, t_param *param)
{
  int		i;

  i = 0;
  if (av[0] == '-' || av[0] == '\0')
    my_exitstr("Bad argument for -p.\n", -1);
  else
    {
      if ((param->pions = malloc(sizeof(char) * my_strlen(av))) == NULL)
	my_exitstr("Malloc error, program must close.\n", -1);
      while (av[i] != '\0')
	{
	  param->pions[i] = av[i];
	  i = i + 1;
	}
      param->pions[i] = '\0';
    }
  return (0);
}

int		arg_code(char *av, t_param *param)
{
  if (av[0] == '-' || av[0] == '\0')
    my_exitstr("Bad argument for -c.\n", -1);
  else
    param->code = av;
  return (0);
}
