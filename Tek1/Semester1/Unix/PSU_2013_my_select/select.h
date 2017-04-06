/*
** select.h for select in /home/moulin_c/rendu/Modules/Unix/My_select/PSU_2013_my_select
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan 19 14:24:28 2014 moulin_c
** Last update Sun Jan 19 17:57:02 2014 moulin_c
*/

#ifndef SELECT_H_
# define SELECT_H_

# include <stdlib.h>
# include <ncurses/curses.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include "mylist.h"

typedef struct	s_select
{
  int		pos;
}		t_select;

void	init_list(t_list **list, char **argv);
int	init_struct(struct termios *term, struct termios *prev);
int	main(int argc, char **argv);
void	up_or_down(char *buffer, int argc, t_select *var);
int	gere_key(int argc, struct termios prev, t_list *list);
void	highlisght(t_list *tmp, t_select *var);
void	underline(t_list *list, t_list *tmp, t_select *var, char *buffer);
void	disp_select(t_list *list, char *buffer, t_select *var);
int	my_show_selected(t_list *list, struct termios prev);
int	do_it(int nb);
int	do_caps(char *str);

#endif /* !SELECT_H_ */
