/*
** main.c for sud-au-cul in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Rush_Sudo
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Mar  1 00:39:02 2014 moulin_c
** Last update Sun Mar  2 19:57:55 2014 moulin_c
*/

#include "sudoku.h"
#include "get_next_line.h"

void		freetab(t_sudo **tab)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i != 8)
    free(tab[i++]);
  free(tab);
}

int		my_sudoki(void)
{
  t_sudo	**tab;
  t_param	var;
  int		turn;
  char		*str;

  turn = 0;
  str = get_next_line(0);
  if (!str)
    return (-1);
  while (str)
    {
      if (turn)
	my_putstr("####################\n");
      if (parser(&tab, str) == -1)
	return (-2);
      if (resolve(tab, &var) == -1)
	return (-3);
      display_tab(tab);
      turn = 1;
      free(str);
      freetab(tab);
      str = get_next_line(0);
    }
  return (0);
}

int		main(void)
{
  int		check;

  check = my_sudoki();
  my_putstr("\033[0m");
  if (check == -1)
    my_putstr("Void file\n");
  else if (check == -2)
    my_putstr("Wrong grid format\n");
  else if (check == -3)
    my_putstr("Unsolvable grid\n");
  return (0);
}
