/*
** add_elem.c for lemin in /home/moulin_c/rendu/code_tek/make_list
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 25 17:55:05 2014 moulin_c
** Last update Sat Apr 26 19:24:43 2014 moulin_c
*/

#include "mylist.h"
#include "graph.h"

int	add_elem(t_adj **list, char *name, int flag)
{
  t_adj	*elem;
  t_adj	*tmp;

  tmp = *list;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (1);
  elem->name = name;
  elem->flag = flag;
  elem->adjacents = NULL;
  elem->next = NULL;
  if (tmp == NULL)
    {
      *list = elem;
      return (0);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  return (0);
}
