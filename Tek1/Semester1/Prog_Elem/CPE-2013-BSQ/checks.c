/*
** checks.c for bsq in /home/moulin_c/rendu/Modules/C_Prog_Elem/BSQ/CPE-2013-BSQ
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  8 18:18:34 2013 moulin_c
** Last update Sun Dec  8 18:30:12 2013 moulin_c
*/

#include "bsq.h"

int	check_line(char **tab, int line, int column, int nb_check)
{
  int	check;
  int	i;

  i = 0;
  while (i < nb_check + 1)
    {
      if (tab[line][column] == 'o')
	return (1);
      line--;
      i++;
    }
  return (0);
}

int	check_column(char **tab, int line, int column, int nb_check)
{
  int	check;
  int	i;

  i = 0;
  while (i < nb_check + 1)
    {
      if (tab[line][column] == 'o')
	return (1);
      column--;
      i++;
    }
  return (0);
}

t_param		check_obstacle(char **tab, int nb_line, int nb_column, t_param var)
{
  while (var.s_line < nb_line && var.s_col < nb_column)
    {
      var.check_li = check_line(tab, var.s_line, var.s_col, var.last);
      var.check_col = check_column(tab, var.s_line, var.s_col, var.last);
      if (var.check_col == 0 && var.check_li == 0)
	{
	  var.s_line++;
	  var.s_col++;
	  var.last++;
	}
      else
	var.s_line = nb_line;
    }
  return (var);
}
