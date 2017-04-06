/*
** gere_select.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Feb  5 22:27:20 2014 moulin_c
** Last update Sun Feb 16 19:06:31 2014 moulin_c
*/

#include "alum.h"

void	unselect_all(t_param *var, t_alum **tabl)
{
  int	i;
  int	j;
  int	stat;

  i = 0;
  stat = 1;
  while (i < var->lines_max)
    {
      j = 0;
      if (i != var->i)
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

int	check_last(t_param *var, t_alum **tabl)
{
  int	i;
  int	j;
  int	stat;
  int	check;

  i = 0;
  check = 0;
  stat = 1;
  while (i < var->lines_max)
    {
      j = 0;
      while (j < stat)
	{
	  if (tabl[i][j].select == 0 && tabl[i][j].letter == '|')
	    check++;
	  j++;
	}
      stat = stat + 2;
      i++;
    }
  if (check > 1)
    return (0);
  return (1);
}

int	check_selections(t_param *var, t_alum **tabl)
{
  int	i;
  int	j;
  int	stat;

  i = 0;
  stat = 1;
  while (i < var->lines_max)
    {
      j = 0;
      if (i != var->i)
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

void	gere_select(t_param *var, t_alum **tabl)
{
  if (check_selections(var, tabl) == 1)
    unselect_all(var, tabl);
  if (tabl[var->i][var->j].select == 1)
    tabl[var->i][var->j].select = 0;
  else if (tabl[var->i][var->j].taken == 0 && check_last(var, tabl) == 0)
    tabl[var->i][var->j].select = 1;
}
