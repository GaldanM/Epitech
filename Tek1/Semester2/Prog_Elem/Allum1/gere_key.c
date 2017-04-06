/*
** gere_key.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Feb  5 22:20:32 2014 moulin_c
** Last update Sun Feb 16 19:06:15 2014 moulin_c
*/

#include "alum.h"

void	gere_up(t_param *var, t_alum **tabl)
{
  tabl[var->i][var->j].on_it = 0;
  if (var->i == 0)
    var->i = var->lines_max - 1;
  else
    {
      (var->i)--;
      if (var->j != 0)
	(var->j)--;
    }
  if (tabl[var->i][var->j].taken == -1)
    (var->j)--;
  tabl[var->i][var->j].on_it = 1;
}

void	gere_down(t_param *var, t_alum **tabl)
{
  tabl[var->i][var->j].on_it = 0;
  if (var->i == var->lines_max - 1)
    {
      var->i = 0;
      var->j = 0;
    }
  else
    {
      (var->i)++;
      (var->j)++;
    }
  tabl[var->i][var->j].on_it = 1;
}

void	gere_right(t_param *var, t_alum **tabl)
{
  int	i;
  int	j;

  i = var->i;
  j = var->j;
  tabl[var->i][var->j].on_it = 0;
  if (var->j == var->i * 2)
    var->j = 0;
  else
    (var->j)++;
  tabl[var->i][var->j].on_it = 1;
}

void	gere_left(t_param *var, t_alum **tabl)
{
  int	i;
  int	j;

  i = var->i;
  j = var->j;
  tabl[var->i][var->j].on_it = 0;
  if (var->j == 0)
    var->j = var->i * 2;
  else
    (var->j)--;
  tabl[var->i][var->j].on_it = 1;
}

void	gere_arrows(char *buffer, t_param *var, t_alum **tabl)
{
  if (buffer[2] == 65)
    gere_up(var, tabl);
  if (buffer[2] == 66)
    gere_down(var, tabl);
  if (buffer[2] == 67)
    gere_right(var, tabl);
  if (buffer[2] == 68)
    gere_left(var, tabl);
}
