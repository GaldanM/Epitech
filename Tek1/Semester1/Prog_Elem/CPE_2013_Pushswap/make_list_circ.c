/*
** make_list_circ.c for make_circ in 
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan  5 11:35:26 2014 moulin_c
** Last update Mon Jan  6 04:05:32 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"

t_list	*make_list_circ(void)
{
  t_list	*root;

  root = malloc(sizeof(t_list));
  if (root != NULL)
    {
      root->prev = root;
      root->next = root;
    }
  else
    {
      my_putstr("MALLOC FAILED\n");
      exit(1);
    }
  return (root);
}
