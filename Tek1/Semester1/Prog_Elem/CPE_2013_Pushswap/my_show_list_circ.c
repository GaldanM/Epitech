/*
** my_show_list_circ.c for show_list_circ in 
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan  5 12:43:34 2014 moulin_c
** Last update Mon Jan  6 17:45:07 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"

void	my_show_list_circ(t_list *list)
{
  t_list	*end;

  end = list->prev;
  while (list != end)
    {
      list = list->next;
      my_put_nbr(list->nb);
      if (list != end)
	my_putstr("  ");
    }
}
