/*
** foncs_lists.c for lists in /home/moulin_c/rendu/colle3_moulin_c_OaHTo/srcs
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon May 12 20:07:52 2014 moulin_c
** Last update Mon May 12 20:29:52 2014 moulin_c
*/

#include	<stdlib.h>
#include	"lists.h"

t_items		*make_items(void)
{
  t_items	*elem;

  elem = malloc(sizeof(elem));
  if (elem)
    {
      elem->prev = NULL;
      elem->nbr = 0;
      elem->next = NULL;
    }
  else
    exit(2);
  return (elem);
}

void		*add_item(t_items **list, t_items *param)
{
  t_items	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = param;
  param->prev = tmp;
  param->next = NULL;
}
