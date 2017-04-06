/*
** foncs_list.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Feb  4 19:47:52 2014 moulin_c
** Last update Sun Feb 16 19:05:44 2014 moulin_c
*/

#include "alum.h"

void		fill_line(t_alum **tabl, int i, int stat)
{
  int		j;

  j = 0;
  while (j < stat)
    {
      tabl[i][j].taken = 0;
      tabl[i][j].select = 0;
      tabl[i][j].on_it = 0;
      tabl[i][j++].letter = '|';
    }
  tabl[i][j].taken = -1;
}

t_alum		**create_list(int nb_lines)
{
  t_alum	**tabl;
  int		i;
  int		stat;

  i = 0;
  stat = 1;
  if ((tabl = malloc(sizeof(t_alum *) * nb_lines)) == NULL)
    return (tabl);
  while (i < nb_lines)
    {
      if ((tabl[i] = malloc(sizeof(t_alum) * stat)) == NULL)
	return (tabl);
      fill_line(tabl, i, stat);
      stat = stat + 2;
      i++;
    }
  tabl[0][0].on_it = 1;
  return (tabl);
}

void		disp_list(t_param *var, t_alum **tabl, int i)
{
  int		j;

  j = 0;
  while (j < var->nb_alum)
    {
      if (tabl[i][j].select == 1)
	do_caps("so");
      if (tabl[i][j].on_it == 1)
	do_caps("us");
      my_putchar(tabl[i][j].letter);
      if (tabl[i][j].on_it == 1)
	do_caps("ue");
      if (tabl[i][j].select == 1)
	do_caps("se");
      j++;
    }
}

void		disp_matches(t_param *var, t_alum **tabl)
{
  int		counter;
  int		j;
  int		i;

  i = 0;
  var->nb_alum = 1;
  var->space = calc_matches(var->lines_max) / 2;
  while (i < var->lines_max)
    {
      counter = 0;
      while (counter < var->space)
	{
	  write(1, " ", 1);
	  counter++;
	}
      disp_list(var, tabl, i);
      (var->space)--;
      my_putstr("\n\t");
      var->nb_alum = var->nb_alum + 2;
      i++;
    }
}
