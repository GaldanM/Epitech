/*
** gere_key.c for select in /home/moulin_c/rendu/Modules/Unix/My_select/PSU_2013_my_select
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan 15 18:52:14 2014 moulin_c
** Last update Sun Jan 19 18:01:42 2014 moulin_c
*/

#include "select.h"

void		up_or_down(char *buffer, int argc, t_select *var)
{
  if (buffer[2] == 65)
    {
      if (var->pos == 1)
	var->pos = argc - 1;
      else
	var->pos--;
    }
  else if (buffer[2] == 66)
    {
      if (var->pos == argc - 1)
	var->pos = 1;
      else
	var->pos++;
    }
}

int		gere_key(int argc, struct termios prev, t_list *list)
{
  t_select	var;
  char		buffer[10];
  char		*getcm;
  char		*tgo;

  var.pos = 1;
  if ((getcm = tgetstr("cm", NULL)) == NULL)
    return (0);
  do_caps("cl");
  my_putstr("_________Select your choice(s)_________\n\n");
  while (42)
    {
      disp_select(list, buffer, &var);
      if (read(0, buffer, 10) < 0)
	return (-1);
      if ((tgo = tgoto(getcm, 0, 2)) == NULL)
	return (-1);
      if (tputs(tgo, 1, do_it) == -1)
	return (-1);
      if (buffer[0] == '\n')
	my_show_selected(list, prev);
      else if (buffer[0] == 27 && buffer[1] == 91)
	up_or_down(buffer, argc, &var);
    }
  return (0);
}
