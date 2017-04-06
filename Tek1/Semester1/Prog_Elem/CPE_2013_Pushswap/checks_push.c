/*
** checks_push.c for pushswap in /home/moulin_c/mbin
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan  6 16:47:11 2014 moulin_c
** Last update Mon Jan  6 16:51:58 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"
#include "push.h"

void		check_swap(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;

  elem = (*list_a)->next;
  if (elem->nb > elem->next->nb)
    my_sa(list_a, list_b, var);
  if (elem->nb > elem->prev->prev->nb)
    my_rra(list_a, list_b, var);
}

int		*check_first_size(t_list **list_a)
{
  t_list	*elem;
  int		save;
  int		save_base;
  int		*save_addr;

  elem = *list_a;
  elem = elem->next;
  save = elem->next->nb;
  save_base = elem->nb;
  while (elem != *list_a)
    {
      if (elem->nb < save)
	save = elem->nb;
      elem = elem->next;
    }
  if (save == save_base)
    return (NULL);
  else
    {
      save_addr = &save;
      return (save_addr);
    }
}

int		check_sort_list(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;
  int		save;

  elem = *list_a;
  elem = elem->next;
  save = elem->next->nb;
  while (elem != (*list_a)->prev)
    {
      if (elem->nb > save)
	{
	  check_swap(list_a, list_b, var);
	  return (0);
	}
      elem = elem->next;
      save = elem->next->nb;
    }
  if ((*list_b)->prev == *list_b)
    return (1);
  else
    bsort_to_a(list_a, list_b, var);
}
