/*
** main.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/allum1-2018-moulin_c
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Feb  3 13:41:44 2014 moulin_c
** Last update Fri Feb  7 16:32:32 2014 moulin_c
*/

#include "alum.h"

int			calc_matches(int lines_max)
{
  int			i;
  int			max_matches;

  i = 1;
  max_matches = 1;
  while (i < lines_max)
    {
      max_matches = max_matches + 2;
      i++;
    }
  return (max_matches);
}

int			check_read(char *buffer)
{
  int			i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] < 48 || buffer[i] > 57)
	return (1);
      i++;
    }
  return (0);
}

int			init_param(t_param *var)
{
  if (ask_players(var) == -1 || ask_lines(var) == -1)
    return (-1);
  var->turn = 1;
  var->i = 0;
  var->j = 0;
  return (0);
}

int			init(struct termios *term, struct termios *prev, t_param *var)
{
  if (tcgetattr(0, term) == -1)
    return (-1);
  *prev = *term;
  if (tgetent(NULL, "xterm") == -1)
    return (-1);
  if (init_param(var) == -1)
    return (-1);
  do_caps("vi");
  term->c_lflag &= ~ICANON;
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  term->c_lflag &= ~ECHO;
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
  return (0);
}

int			main(int argc, char **argv)
{
  struct termios	term;
  struct termios	prev;
  t_param		var;
  t_alum		**tabl;

  if (init(&term, &prev, &var) == -1)
    return (-1);
  tabl = create_list(var.lines_max);
  if (!tabl)
    return (-1);
  game(&var, tabl);
  if (tcsetattr(0, 0, &prev) == -1)
    return (-1);
  do_caps("cl");
  do_caps("ve");
  return (0);
}
