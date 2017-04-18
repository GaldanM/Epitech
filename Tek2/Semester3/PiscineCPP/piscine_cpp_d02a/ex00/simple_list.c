/*
** simple_list.c for simple_list in /home/moulin_c/rendu/piscine_cpp_d02a/ex00
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Jan  9 09:50:27 2015 Galdan MOULINNEUF
** Last update Fri Jan  9 09:52:50 2015 Galdan MOULINNEUF
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"simple_list.h"

unsigned int	list_get_size(t_list list)
{
  int	size = 0;

  while (list != NULL)
    {
      list = list->next;
      size++;
    }
  return (size);
}

t_bool		list_is_empty(t_list list)
{
  if (list == NULL)
    return (TRUE);
  return (FALSE);
}

void		list_dump(t_list list)
{
  t_list	elem;

  elem = list;
  while (elem)
    {
      printf("%f\n", elem->value);
      elem = elem->next;
    }
}

t_bool		list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	new_elem;

  if ((new_elem = malloc(sizeof(t_list *))) == NULL)
    return (FALSE);
  new_elem->value = elem;
  new_elem->next = (*front_ptr);
  (*front_ptr) = new_elem;
  return (TRUE);
}

t_bool		list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_list	tmp;
  t_list	new_elem;

  tmp = *front_ptr;
  if ((new_elem = malloc(sizeof(t_list *))) == NULL)
    return (FALSE);
  new_elem->next = NULL;
  new_elem->value = elem;
  while ((tmp) && (tmp)->next)
    (tmp) = (tmp)->next;
  if ((tmp))
    (tmp)->next = new_elem;
  else
    (*front_ptr) = new_elem;
  return (TRUE);
}

t_bool		list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
  t_list	tmp;
  t_list	new_elem;
  t_list	save_elem;
  unsigned int	pos;

  pos = 0;
  tmp = *front_ptr;
  position -= 1;
  if ((new_elem = malloc(sizeof(t_list *))) == NULL)
    return (FALSE);
  new_elem->next = NULL;
  new_elem->value = elem;
  if (tmp == NULL)
    {
      (*front_ptr) = new_elem;
      return (TRUE);
    }
  while (tmp && tmp->next && pos < position)
    {
      tmp = tmp->next;
      pos++;
    }
  save_elem = tmp->next;
  tmp->next = new_elem;
  new_elem->next = save_elem;
  return (TRUE);
}

t_bool		list_del_elem_at_front(t_list *front_ptr)
{
  t_list	save;

  if ((*front_ptr) == NULL)
    return (FALSE);
  save = (*front_ptr);
  (*front_ptr) = (*front_ptr)->next;
  free(save);
  return (TRUE);
}

t_bool		list_del_elem_at_back(t_list *front_ptr)
{
  t_list	tmp;

  tmp = *front_ptr;
  if (tmp == NULL)
    return (FALSE);
  while (tmp->next && tmp->next->next)
    tmp = tmp->next;
  free(tmp->next);
  tmp->next = NULL;
  return (TRUE);
}

t_bool		list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list	tmp;
  t_list	save;
  unsigned int		pos = 0;

  tmp = *front_ptr;
  save = tmp;
  position -= 1;
  while (pos < position && tmp && tmp->next)
    {
      tmp = tmp->next;
      pos++;
    }
  pos = 0;
  while (pos < position && save && save->next)
    {
      save = save->next;
      pos++;
    }
  save = save->next->next;
  tmp->next = save;
  return (FALSE);
}

double		list_get_elem_at_front(t_list list)
{
  if (list != NULL)
    return (list->value);
  return (0);
}

double		list_get_elem_at_back(t_list list)
{
  if (list != NULL)
    {
      while (list && list->next)
	list = list->next;
      return (list->value);
    }
  return (0);
}

double		list_get_elem_at_position(t_list list, unsigned int position)
{
  unsigned int	pos;

  pos = 0;
  position -= 1;
  if (!list)
    return (0);
  while (pos <= position && list)
    {
      pos++;
      list = list->next;
    }
  if (list)
    return (list->value);
  return (0);
}

t_node		*list_get_first_node_with_value(t_list list, double value)
{
  while (list != NULL)
    {
      if (list->value == value)
	return (list);
      list = list->next;
    }
  return (NULL);
}
