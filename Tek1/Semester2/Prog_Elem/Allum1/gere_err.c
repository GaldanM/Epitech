/*
** gere_err.c for alum in /home/moulin_c/rendu/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Feb  7 15:17:40 2014 moulin_c
** Last update Fri Feb  7 15:18:27 2014 moulin_c
*/

#include "alum.h"

void	unselect_tabl(t_param *var, t_alum **tabl)
{
  int	i;
  int	j;
  int	stat;

  i = 0;
  stat = 1;
  while (i < var->lines_max)
    {
      j = 0;
      while (j < stat)
	{
	  if (tabl[i][j].select == 1)
	    tabl[i][j].select = 0;
	  j++;
	}
      stat = stat + 2;
      i++;
    }
}

int	check_select(t_param *var, t_alum **tabl)
{
  int	i;
  int	j;
  int	stat;

  i = 0;
  stat = 1;
  while (i < var->lines_max)
    {
      j = 0;
      while (j < stat)
	{
	  if (tabl[i][j].select == 1)
	    return (1);
	  j++;
	}
      stat = stat + 2;
      i++;
    }
  return (0);
}
