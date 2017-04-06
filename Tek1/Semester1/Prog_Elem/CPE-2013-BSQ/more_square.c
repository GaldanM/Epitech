/*
** more_square.c for bsq in /home/moulin_c/rendu/Modules/C_Prog_Elem/BSQ/CPE-2013-BSQ
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  8 18:16:42 2013 moulin_c
** Last update Sun Dec  8 18:30:12 2013 moulin_c
*/

#include "bsq.h"

char	**replace_tab(char **tab, t_param var, int size)
{
  int	x;
  int	y;

  var.i = 0;
  var.j = 0;
  x = var.pos_x;
  y = var.pos_y;
  while (var.i < size)
    {
      while (var.j < size)
	{
	  tab[var.pos_y][var.pos_x] = 'x';
	  var.pos_x++;
	  var.j++;
	}
      var.pos_x = x;
      var.pos_y++;
      var.i++;
      var.j = 0;
    }
  my_show_wordtab(tab);
  free(tab);
  close(var.file);
  exit(1);
}

int		more_square(char **tab, int nb_line, int nb_column, t_param var)
{
  static int	save = 0;
  static int	column = 0;
  static int	line = 0;

  var.last = 0;
  var.s_col = column;
  var.s_line = line;
  var = check_obstacle(tab, nb_line, nb_column, var);
  if (line == nb_line && column == nb_column)
    replace_tab(tab, var, save);
  if (line == nb_line)
    {
      line = 0;
      column++;
    }
  else
    line++;
  if (var.last > save)
    {
      var.pos_x = column;
      var.pos_y = line - 1;
    }
  save = COMPARE(var.last, save);
  more_square(tab, nb_line, nb_column, var);
}
