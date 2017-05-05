/*
** display.c for sud_au_cul in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Rush_Sudo
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Mar  1 15:53:19 2014 moulin_c
** Last update Sun Mar  2 16:37:34 2014 moulin_c
*/

#include "sudoku.h"

void		display_tab(t_sudo **tab)
{
  t_param	disp;

  my_putstr("\033[32m");
  disp.i = 0;
  my_putstr("|------------------|\n");
  while (disp.i < 9)
    {
      disp.j = 0;
      my_putstr("| ");
      while (disp.j < 9)
	{
	  if (tab[disp.i][disp.j].key == 1)
	    my_printf("%s%d", "\033[34m", tab[disp.i][disp.j].num);
	  else
	    my_printf("%s%d", "\033[31m", tab[disp.i][disp.j].num);
	  my_putstr("\033[32m");
	  (disp.j)++;
	  if (disp.j < 9)
	    my_putchar(' ');
	}
      my_putstr("|\n");
      (disp.i)++;
      if (disp.i == 9)
      	my_putstr("|------------------|\n");
    }
}
