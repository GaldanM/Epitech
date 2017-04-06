/*
** main.c for select in /home/moulin_c/rendu/Modules/Unix/My_select/PSU_2013_my_select
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan 15 18:34:46 2014 moulin_c
** Last update Sun Jan 19 18:02:37 2014 moulin_c
*/

#include "select.h"

void			init_list(t_list **list, char **argv)
{
  int			i;

  i = 1;
  *list = make_list_circ();
  while (argv[i])
    {
      add_elem_circ_end(list, argv[i], i);
      i++;
    }
}

int			init_struct(struct termios *term, struct termios *prev)
{
  tcgetattr(0, term);
  *prev = *term;
  if (tgetent(NULL, "xterm") == -1)
    return (-1);
  do_caps("vi");
  term->c_lflag &= ~ICANON;
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  term->c_lflag &= ~ECHO;
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
}

int			main(int argc, char **argv)
{
  t_list		*list;
  struct termios	term;
  struct termios	prev;

  if (argc == 1)
    {
      my_putstr("Enter your choices please\n");
      return (-1);
    }
  init_struct(&term, &prev);
  init_list(&list, argv);
  gere_key(argc, prev, list);
  tcsetattr(0, 0, &prev);
  do_caps("ve");
  return (0);
}
