/*
** resolve.c for sud_au_cul in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Rush_Sudo
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Mar  1 15:49:33 2014 moulin_c
** Last update Sat Mar  1 16:28:08 2014 moulin_c
*/

#include "sudoku.h"

int	resolve_it(t_sudo **tab, t_param *var)
{
  if (tab[var->i][var->j].num == 0)
    var->k = 1;
  if (tab[var->i][var->j].key == 1)
    on_hard_key(tab, var);
  else
    {
      while (var->k <= 9 && var->k > 0)
	find_good(tab, var);
      if (var->k != -1)
	{
	  if (whle_hard(tab, var) == -1)
	    return (-1);
	}
    }
  return (0);
}

int	resolve(t_sudo **tab, t_param *var)
{
  var->i = 0;
  var->j = 0;
  while ((var->i * var->j) < 64)
    if (resolve_it(tab, var) == -1)
      return (-1);
  if (resolve_it(tab, var) == -1)
    return (-1);
  return (0);
}
