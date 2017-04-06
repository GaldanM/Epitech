/*
** add_elem_circ_before.c for add_circ_before in 
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan  5 11:55:50 2014 moulin_c
** Last update Sun Jan 19 17:59:31 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"

void		add_elem_circ_end(t_list **list, char *str, int id)
{
  t_list	*elem;

  elem = *list;
  elem = malloc(sizeof(t_list));
  if (elem != NULL)
    {
      elem->prev = (*list)->prev;
      elem->id = id;
      elem->data = str;
      elem->select = 0;
      elem->next = (*list);
      (*list)->prev->next = elem;
      (*list)->prev = elem;
    }
  else
    {
      my_putstr("MALLOC FAILED\n");
      exit(1);
    }
}
