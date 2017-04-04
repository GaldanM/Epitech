/*
** make_list_circ.c for make_circ in 
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan  5 11:35:26 2014 moulin_c
** Last update Sun Jan 19 15:39:03 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"

t_list		*make_list_circ(void)
{
  t_list	*root;

  root = malloc(sizeof(t_list));
  if (root != NULL)
    {
      root->prev = root;
      root->id = 0;
      root->data = NULL;
      root->select = 0;
      root->next = root;
    }
  else
    {
      my_putstr("MALLOC FAILED\n");
      exit(1);
    }
  return (root);
}
