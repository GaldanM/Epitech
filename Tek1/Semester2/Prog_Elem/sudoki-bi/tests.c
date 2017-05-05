/*
** tests.c for sud_au_cul in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Rush_Sudo
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Mar  1 15:50:28 2014 moulin_c
** Last update Sat Mar  1 16:28:53 2014 moulin_c
*/

#include "sudoku.h"

int	test_line(t_sudo **tab, t_param *var)
{
  int	x;
  int	y;

  x = var->i;
  y = 0;
  while (y <= 8)
    {
      if (tab[x][y].num == var->k)
	return (0);
      y++;
    }
  return (1);
}

int	test_column(t_sudo **tab, t_param *var)
{
  int	x;
  int	y;

  x = 0;
  y = var->j;
  while (x <= 8)
    {
      if (tab[x][y].num == var->k)
	return (0);
      x++;
    }
  return (1);
}

int	test_square(t_sudo **tab, int i, int j, int k)
{
  int	x;
  int	y;

  x = i - (i % 3);
  y = j - (j % 3);
  i = x;
  while (i < x + 3)
    {
      j = y;
      while (j < y + 3)
	{
	  if (tab[i][j].num == k)
	    return (0);
	  j++;
	}
      i++;
    }
  return (1);
}

int	test_k(t_sudo **tab, t_param *var)
{
  if (test_line(tab, var) &&
      test_column(tab, var) &&
      test_square(tab, var->i, var->j, var->k))
    return (1);
  return (0);
}
