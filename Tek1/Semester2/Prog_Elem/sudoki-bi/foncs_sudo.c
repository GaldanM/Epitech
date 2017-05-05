/*
** foncs_sudo.c for sud_au_cul in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Rush_Sudo
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Mar  1 15:52:21 2014 moulin_c
** Last update Sun Mar  2 16:23:18 2014 moulin_c
*/

#include "sudoku.h"

void	on_hard_key(t_sudo **tab, t_param *var)
{
  (var->j)++;
  if (var->j == 9)
    {
      var->j = 0;
      (var->i)++;
    }
}

void	find_good(t_sudo **tab, t_param *var)
{
  if (test_k(tab, var) == 1)
    {
      tab[var->i][var->j].num = var->k;
      (var->j)++;
      if (var->j == 9)
	{
	  var->j = 0;
	  (var->i)++;
	}
      var->k = -1;
    }
  else
    (var->k)++;
}

int	decrem(t_param *var)
{
  (var->j)--;
  if (var->i == 0 && var->j < 0)
    return (-1);
  if (var->j == -1)
    {
      var->j = 8;
      (var->i)--;
    }
  return (0);
}

int	whle_hard(t_sudo **tab, t_param *var)
{
  tab[var->i][var->j].num = 0;
  if (decrem(var) == -1)
    return (-1);
  while (tab[var->i][var->j].key == 1)
    if (decrem(var) == -1)
      return (-1);
  var->k = tab[var->i][var->j].num;
  return (0);
}

