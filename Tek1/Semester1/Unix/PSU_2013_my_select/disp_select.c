/*
** disp_select.c for select in /home/moulin_c/rendu/Modules/Unix/My_select/PSU_2013_my_select
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan 19 14:45:26 2014 moulin_c
** Last update Sun Jan 19 17:57:27 2014 moulin_c
*/

#include "select.h"

void		highlight(t_list *tmp, t_select *var)
{
  do_caps("so");
  if (tmp->id == var->pos)
    do_caps("us");
  my_putstr(tmp->data);
  if (tmp->id == var->pos)
    do_caps("ue");
  do_caps("se");
}

void		underline(t_list *list, t_list *tmp, t_select *var, char *buffer)
{
  do_caps("us");
  if (buffer[0] == ' ')
    {
      if (tmp->select == 0)
	tmp->select = 1;
      else
	tmp->select = 0;
    }
  if (tmp->select == 0)
    my_putstr(tmp->data);
  do_caps("ue");
}

void		disp_select(t_list *list, char *buffer, t_select *var)
{
  t_list	*tail;
  t_list	*tmp;

  tail = list->prev;
  tmp = list;
  while (tmp != tail)
    {
      tmp = tmp->next;
      if (tmp->id == var->pos)
	underline(list, tmp, var, buffer);
      if (tmp->select == 1)
	highlight(tmp, var);
      else if (tmp->id != var->pos && tmp->select == 0)
	my_putstr(tmp->data);
      if (tmp != tail)
	my_putchar('\n');
    }
}

int		my_show_selected(t_list *list, struct termios prev)
{
  t_list	*tail;
  t_list	*tmp;

  tail = list->prev;
  tmp = list;
  do_caps("cl");
  my_putstr("Your choice(s) : ");
  while (tmp != tail)
    {
      tmp = tmp->next;
      if (tmp->select == 1)
	my_putstr(tmp->data);
      if (tmp != tail)
	my_putchar(' ');
    }
  my_putchar('\n');
  do_caps("ve");
  if (tcsetattr(0, 0, &prev) == -1)
    return (-1);
  exit(1);
}
