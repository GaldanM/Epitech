/*
** init_params.c for my_boogle in /home/sement_s/rendu/colle6_moulin_c_7TtAi
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon Jun  2 19:45:38 2014 Stephen SEMENT
** Last update Mon Jun  2 20:30:04 2014 Stephen SEMENT
*/

#include	<stdlib.h>
#include	"bparam.h"

int		my_grid_to_param(char *str, t_param *param)
{
  int		i;

  i = 0;
  if ((param->grid = malloc(sizeof(char) * my_strlen(str))) == NULL)
    {
      my_putstr("Malloc error\n");
      return (-1);
    }
  while (str[i] != '\0')
    {
      param->grid[i] = str[i];
      i = i + 1;
    }
  return (0);
}

int		my_word_to_param(char *str, t_param *param)
{
  int		i;

  i = 0;
  if ((param->word = malloc(sizeof(char) * my_strlen(str))) == NULL)
    {
      my_putstr("Malloc error\n");
      return (-1);
    }
  while (str[i] != '\0')
    {
      param->word[i] = str[i];
      i = i + 1;
    }
  return (0);
}

int		init_params(t_param *param)
{
  param->size = 4;
  param->grid = NULL;
  param->word = NULL;
  param->color = 0;
}
