/*
** del_elem_circ_begin.c for del_elem_circ_beg in 
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan  5 12:26:07 2014 moulin_c
** Last update Sun Jan  5 12:43:00 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"

void	del_elem_circ_end(t_list **list)
{
  t_list	*elem;

  elem = (*list)->prev;
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
