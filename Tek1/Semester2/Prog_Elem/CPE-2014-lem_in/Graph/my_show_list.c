/*
** my_show_list.c for linked strings in 
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan 20 11:16:05 2014 moulin_c
** Last update Sat Apr 26 16:32:56 2014 moulin_c
*/

#include "mylist.h"

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf("elem %d = %s\n", tmp->i, tmp->line);
      tmp = tmp->next;
    }
}
