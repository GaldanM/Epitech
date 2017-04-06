/*
** gere_enter.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Feb  5 22:40:15 2014 moulin_c
** Last update Fri Feb  7 15:16:09 2014 moulin_c
*/

#include "alum.h"

void	gere_enter(t_param *var, t_alum **tabl)
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
	    {
	      tabl[i][j].taken = 1;
	      tabl[i][j].letter = ' ';
	    }
	  j++;
	}
      stat = stat + 2;
      i++;
    }
}
