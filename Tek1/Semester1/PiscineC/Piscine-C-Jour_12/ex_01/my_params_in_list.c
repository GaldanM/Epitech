/*
** my_params_in_list.c for my_params_in_list in /home/moulin_c/rendu/Piscine-C-Jour_12/ex_01
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 20:44:46 2013 moulin_c
** Last update Wed Oct 23 22:03:38 2013 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"

int		my_put_in_list(t_list **list, void *data)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (0);
}

void		my_show_list(struct s_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

t_list		*my_params_in_list(int ac, char **av)
{
  int		counter;
  t_list	*list;

  counter = 0;
  list = NULL;
  while (ac != 0)
    {
      my_put_in_list(&list, av[counter]);
      ac = ac - 1;
      counter = counter + 1 ;
    }
  return (list);
}
