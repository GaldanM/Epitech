/*
** my_put_in_list_end.c for my_put_in_list_end in /home/moulin_c/rendu/Piscine-C-Jour_12/test
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 15:57:27 2013 moulin_c
** Last update Sat Apr 26 16:31:38 2014 moulin_c
*/

#include "mylist.h"

int		my_put_in_list_end(t_list **list, char *value, int i)
{
  t_list	*elem;
  t_list	*tmp;

  tmp = *list;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (1);
  elem->i = i;
  elem->line = value;
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
