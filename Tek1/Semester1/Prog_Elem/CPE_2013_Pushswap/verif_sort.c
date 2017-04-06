/*
** verif_sort.c for verif in /home/moulin_c/rendu/Modules/C_Prog_Elem/PushSwap/CPE-2013-push_swap
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan  5 21:00:51 2014 moulin_c
** Last update Mon Jan  6 16:50:47 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"
#include "push.h"

void	bsort_to_a(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;

  elem = (*list_b);
  while (elem != (*list_b)->prev)
    my_pa(list_b, list_a, var);
}

void	my_compare_ra(t_list **list_a, t_list **list_b, t_var *var)
{
  if (var->rra < var->ra)
    while (var->rra > 0)
      {
	my_rra(list_a, list_b, var);
	var->rra--;
      }
  else
    while (var->ra > 0)
      {
	my_ra(list_a, list_b, var);
	var->ra--;
      }
}
void	my_rotate(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;
  int		min;
  int		*check;

  var->ra = 0;
  var->rra = 0;
  elem = *list_a;
  if ((check = check_first_size(list_a)) != NULL)
    {
      min = *check;
      while (elem->next->nb != min)
	{
	  var->ra++;
	  elem = elem->next;
	}
      while (elem->next != (*list_a))
	{
	  elem = elem->next;
	  var->rra++;
	}
      my_compare_ra(list_a, list_b, var);
    }
  my_pb(list_a, list_b, var);
}
