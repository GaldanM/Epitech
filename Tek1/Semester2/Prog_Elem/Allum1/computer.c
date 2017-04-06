/*
** IA.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Feb  6 15:33:58 2014 moulin_c
** Last update Fri Feb  7 14:45:27 2014 moulin_c
*/

#include "alum.h"

int	check_line(t_alum **tabl, int i)
{
  int	check;
  int	j;

  check = 0;
  j = 0;
  while (tabl[i][j].taken != -1)
    {
      if (tabl[i][j].letter == '|')
	check++;
      j++;
    }
  return (check);
}

void	del_line(t_param *var, t_alum **tabl, int i)
{
  int	j;

  j = 0;
  tabl[var->i][var->j].on_it = 0;
  while (tabl[i][j].taken != -1)
    {
      if (tabl[i][j].letter != ' ')
	{
	  tabl[i][j].select = 1;
	  tabl[i][j].on_it = 1;
	  display(var, tabl);
	  usleep(500000);
	  tabl[i][j].letter = ' ';
	  tabl[i][j].select = 0;
	  tabl[i][j].on_it = 0;
	  tabl[i][j].taken = 1;
	}
      j++;
    }
}

int	computer_turn(t_param *var, t_alum **tabl)
{
  int	i;
  int	j;

  i = 0;
  while (i < var->lines_max)
    {
      j = 0;
      while (tabl[i][j].taken != -1)
	{
	  if (check_line(tabl, i) > 0)
	    {
	      del_line(var, tabl, i);
	      return (0);
	    }
	  j++;
	}
      i++;
    }
  return (-1);
}
