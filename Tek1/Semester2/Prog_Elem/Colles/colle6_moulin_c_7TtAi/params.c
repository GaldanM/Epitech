/*
** params.c for my_boogle.c in /home/sement_s/rendu/colle6_moulin_c_7TtAi
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon Jun  2 19:25:03 2014 Stephen SEMENT
** Last update Mon Jun  2 21:14:11 2014 Stephen SEMENT
*/

#include	<stdlib.h>
#include	"bparam.h"

int		check_grid(char *str, t_param *param)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
	return (-1);
      i = i + 1;
    }
  if (my_grid_to_param(str, param) == -1)
    return (-1);
  return (0);
}

int		check_size(char *str, t_param *param)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i = i + 1;
    }
  param->size = my_atoi(str);
  return (0);
}

int		check_word(char *str, t_param *param)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
	return (-1);
      i = i + 1;
    }
  if (my_word_to_param(str, param) == -1)
    return (-1);
  return (0);
}

int		check_params(int ac, char **av, t_param *param)
{
  int		i;

  i = 1;
  while (i <= ac - 1)
    {
      if (my_strcmp(av[i], "-g") == 0 && av[i + 1] != NULL)
	{
	  if (check_grid(av[i + 1], param) == -1)
	    return (-1);
	}
      else if (my_strcmp(av[i], "-s") == 0 && av[i + 1] != NULL)
	{
	  if (check_size(av[i + 1], param) == -1)
	    return (-1);
	}
      else if (my_strcmp(av[i], "-w") == 0 && av[i + 1] != NULL)
	{
	  if (check_word(av[i + 1], param) == -1)
	    return (-1);
	}
      else
	is_there_color(av[i], param);
      i = i + 1;
    }
  return (0);
}
