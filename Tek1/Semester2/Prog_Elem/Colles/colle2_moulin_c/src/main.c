/*
** main.c for my_mastermind in /home/sement_s/rendu/colle2_moulin_c/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May  5 19:20:25 2014 Stephen SEMENT
** Last update Mon May  5 22:51:24 2014 moulin_c
*/

#include	<stdlib.h>
#include	"my.h"

int		check_arguments(int ac, char **av, t_param *param)
{
  int		i;
  int		p_set;

  i = 1;
  p_set = 0;
  while (i < (ac - 1))
    {
      if (my_strcmp(av[i], "-s") == 1)
	arg_slots(av[i + 1], param);
      if (my_strcmp(av[i], "-t") == 1)
	arg_try(av[i + 1], param);
      if (my_strcmp(av[i], "-p") == 1)
	{
	  arg_pions(av[i + 1], param);
	  p_set = 1;
	}
      if (my_strcmp(av[i], "-c") == 1)
	arg_code(av[i + 1], param);
      i = i + 1;
    }
  if (p_set == 0)
    default_pions(param);
  my_mastermind(param);
}

int		init_struct(t_param *param)
{
  param->pions = NULL;
  param->code = NULL;
  param->try = 10;
  param->slot = 4;
  param->win = 0;
  param->check = 0;
  param->key = 0;
}

int		main(int ac, char **av)
{
  t_param	param;

  if (ac > 9)
    {
      my_putstr("Please refer to the README for proper usage.\n");
      return (-1);
    }
  else
    {
      init_struct(&param);
      check_arguments(ac, av, &param);
    }
  return (0);
}
