/*
** list_foncs.c for list_foncs in /home/moulin_c/rendu/Modules/C_Prog_Elem/PushSwap/CPE-2013-push_swap
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Jan  4 22:13:42 2014 moulin_c
** Last update Mon Jan  6 17:43:50 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"
#include "push.h"

void	my_sa(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;

  elem = (*list_a)->next;
  if (elem->next)
    {
      my_swap(&elem->nb, &elem->next->nb);
      if (var->key && !var->va)
	my_putchar(' ');
      my_putstr("sa");
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

void	my_sb(t_list **list_a, t_list **list_b, t_var *var)
{
  t_list	*elem;

  elem = (*list_b)->next;
  if (elem->next)
    {
      my_swap(&elem->nb, &elem->next->nb);
      if (var->key && !var->va)
	my_putchar(' ');
      my_putstr("sb");
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

void	my_ss(t_list **list_a, t_list **list_b, t_var *var)
{
  my_sa(list_a, list_b, var);
  my_sb(list_a, list_b, var);
  if (var->key && !var->va)
    my_putchar(' ');
  my_putstr("ss");
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

void	my_pa(t_list **list_b, t_list **list_a, t_var *var)
{
  if ((*list_b)->next)
    {
      add_elem_circ_begin(list_a, (*list_b)->next->nb);
      del_elem_circ_begin(list_b);
      if (var->key && !var->va)
	my_putchar(' ');
      my_putstr("pa");
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

void	my_pb(t_list **list_a, t_list **list_b, t_var *var)
{
  if ((*list_a)->next)
    {
      add_elem_circ_begin(list_b, (*list_a)->next->nb);
      del_elem_circ_begin(list_a);
      if (var->key && !var->va)
	my_putchar(' ');
      my_putstr("pb");
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
