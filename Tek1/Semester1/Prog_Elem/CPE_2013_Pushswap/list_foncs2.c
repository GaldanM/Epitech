/*
** list_foncs2.c for pushswap in /home/moulin_c/mbin
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan  6 17:39:58 2014 moulin_c
** Last update Mon Jan  6 17:40:50 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"
#include "push.h"

void	my_ra(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;

  elem = (*list_a)->next;
  if (elem->prev)
    {
      add_elem_circ_end(list_a, elem->nb);
      del_elem_circ_begin(list_a);
      if (var->key && !var->va)
	my_putchar(' ');
      my_putstr("ra");
      if (var->va)
	{
	  my_putstr(":\n======================\n");
	  my_putstr("List a -> ");
	  my_show_list_circ(*list_a);
	  my_putstr("\nList b -> ");
	  my_show_list_circ(*list_b);
	  my_putchar('\n');
	  my_putstr("======================\n");
	}
      var->key = 1;
    }
}

void	my_rb(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;

  elem = (*list_b)->next;
  if (elem->prev)
    {
      add_elem_circ_end(list_b, elem->nb);
      del_elem_circ_begin(list_b);
      if (var->key && !var->va)
	my_putchar(' ');
      my_putstr("rb");
      if (var->va)
	{
	  my_putstr(":\n======================\n");
	  my_putstr("List a -> ");
	  my_show_list_circ(*list_a);
	  my_putstr("\nList b -> ");
	  my_show_list_circ(*list_b);
	  my_putchar('\n');
	  my_putstr("======================\n");
	}
      var->key = 1;
    }
}

void	my_rr(t_list **list_a, t_list **list_b, t_var *var)
{
  my_ra(list_a, list_b, var);
  my_rb(list_a, list_b, var);
  if (var->key && !var->va)
    my_putchar(' ');
  my_putstr("rr");
  if (var->va)
    {
      my_putstr(":\n======================\n");
      my_putstr("List a -> ");
      my_show_list_circ(*list_a);
      my_putstr("\nList b -> ");
      my_show_list_circ(*list_b);
      my_putchar('\n');
      my_putstr("======================\n");
    }
  var->key = 1;
}

void	my_rra(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;

  elem = (*list_a)->prev;
  if (elem->next)
    {
      add_elem_circ_begin(list_a, elem->nb);
      del_elem_circ_end(list_a);
      if (var->key && !var->va)
	my_putchar(' ');
      my_putstr("rra");
      if (var->va)
	{
	  my_putstr(":\n======================\n");
	  my_putstr("List a -> ");
	  my_show_list_circ(*list_a);
	  my_putstr("\nList b -> ");
	  my_show_list_circ(*list_b);
	  my_putchar('\n');
	  my_putstr("======================\n");
	}
      var->key = 1;
    }
}

void	my_rrb(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;

  elem = (*list_b)->prev;
  if (elem->next)
    {
      add_elem_circ_begin(list_b, elem->nb);
      del_elem_circ_end(list_b);
      if (var->key && !var->va)
	my_putchar(' ');
      my_putstr("rrb");
      if (var->va)
	{
	  my_putstr(":\n======================\n");
	  my_putstr("List a -> ");
	  my_show_list_circ(*list_a);
	  my_putstr("\nList b -> ");
	  my_show_list_circ(*list_b);
	  my_putchar('\n');
	  my_putstr("======================\n");
	}
      var->key = 1;
    }
}
