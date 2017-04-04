/*
** list_foncs3.c for pushswap in /home/moulin_c/mbin
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan  6 17:41:05 2014 moulin_c
** Last update Mon Jan  6 17:43:48 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"
#include "push.h"

void	my_rrr(t_list **list_a, t_list **list_b, t_var *var)
{
  my_rra(list_a, list_b, var);
  my_rrb(list_a, list_b, var);
  if (var->key && !var->va)
    my_putchar(' ');
  my_putstr("rrr");
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
