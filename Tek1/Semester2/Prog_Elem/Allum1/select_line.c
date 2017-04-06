/*
** select_line.c for alum in /home/moulin_c/rendu/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Feb 10 13:48:02 2014 moulin_c
** Last update Mon Feb 10 14:47:53 2014 moulin_c
*/

#include "alum.h"

void	select_line(t_param *var, t_alum **tabl)
{
  int	j;

  j = 0;
  while (tabl[var->i][j].taken != -1)
    {
      if (tabl[var->i][j].taken == 0 && check_last(var, tabl) == 0)
	tabl[var->i][j].select = 1;
      j++;
    }
}

void	unselect_line(t_param *var, t_alum **tabl)
{
  int	j;

  j = 0;
  while (tabl[var->i][j].taken != -1)
    {
      if (tabl[var->i][j].taken == 0)
	tabl[var->i][j].select = 0;
      j++;
    }
}

void	gere_selectline(t_param *var, t_alum **tabl)
{
  if (check_selections(var, tabl) == 1)
    unselect_all(var, tabl);
  if (tabl[var->i][var->j].select == 1)
    unselect_line(var, tabl);
  else if (tabl[var->i][var->j].taken == 0)
    select_line(var, tabl);
}
