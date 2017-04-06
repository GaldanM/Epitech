/*
** mastermind.c for mastermind in /home/moulin_c/rendu/colle2_moulin_c
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon May  5 19:22:15 2014 moulin_c
** Last update Mon May  5 22:52:12 2014 moulin_c
*/

#include	<stdlib.h>
#include	<time.h>
#include	"my.h"

int		check_pions(t_param *param, char *compare)
{
  int		i;
  int		j;
  int		nb;

  i = 0;
  nb = 0;
  if (my_strlen(compare) != param->slot)
    return (-1);
  while (param->pions[i])
    {
      j = 0;
      while (compare[j])
	{
	  if (param->pions[i] == compare[j])
	    nb++;
	  j++;
	}
      i++;
    }
  if (nb == j)
    return (0);
  my_exitstr("Code should match with pions (\"01234567\" by default)\n", -1);
}

void		check_code(t_param *param)
{
  int		i;
  int		j;

  i = 0;
  param->good = 0;
  param->bad = 0;
  while (param->buffer[i])
    {
      if (param->code[i] == param->buffer[i])
	(param)->good++;
      else
	{
	  j = 0;
	  while (param->code[j])
	    {
	      if (param->code[j] == param->buffer[i])
		(param)->bad++;
	      j++;
	    }
	}
      i++;     
    }
  disp_pions(param);
}

char		*create_code(t_param *param)
{
  char		*code;
  int		i;
  int		random;

  param->key = 1;
  if ((param->code = malloc(sizeof(char) * (param)->slot + 1)) == NULL)
    my_exitstr("Malloc failed\n", -1);
  i = 0;
  srand(time(NULL));
  while (i < param->slot)
    {
      random = rand() % my_strlen(param->pions);
      param->code[i] = param->pions[random];
      i++;
    }
  param->code[i] = '\0';
  return (param->code);
}

int		init_mastermind(t_param *param)
{
  if (param->code == NULL)
    param->code = create_code(param);
  if (param->slot != my_strlen(param->code))
    my_exitstr("Code lenght should match with slot (4 by default)\n", -1);
  check_pions(param, param->code);
  return (0);
}

void		my_mastermind(t_param *param)
{
  int		i;

  i = init_mastermind(param);
  while (i < param->try && param->win == 0)
    {
      if (param->check == 0)
	print_round(i + 1, param->try);
      disp_prompt(param->pions, param->slot);
      if ((param->ret = read(0, param->buffer, 4096)) == -1)
	my_exitstr("Read failed\n" , -1);
      param->buffer[param->ret - 1] = '\0';
      if ((param->check = check_pions(param, param->buffer)) == 0)
	{
	  i++;
	  check_code(param);
	  if (i < param->try && param->win == 0)
	    my_putstr("--\n");
	}
      else
	my_putstr("Mais tu fais quoi là ! Tu es le pire du monde mon gars !\n");
    }
  if (!param->win)
    my_putstr("\nTu n'as pas réussi ! Mais on t'aime quand même !\n");
  if (param->key)
    free(param->code);
}
