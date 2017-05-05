/*
** free.c for malloc in /home/moulin_c/rendu/PSU_2014_malloc
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Feb  3 21:13:45 2015 Galdan MOULINNEUF
** Last update Fri Feb 13 15:27:12 2015 Galdan MOULINNEUF
*/

#include	<unistd.h>
#include	"malloc.h"

extern t_mdata	*g_root;

static void	delete_last(t_mdata *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  brk(elem);
}

static t_mdata	*my_fusion(t_mdata *ptr1, t_mdata *ptr2)
{
  ptr1->next = ptr2->next;
  ptr2->next->prev = ptr1;
  ptr1->end = ptr2->end;
  ptr1->size += ptr2->size + sizeof(t_mdata);
  return (ptr1);
}

void		free(void *ptr)
{
  t_mdata	*tmp;

  tmp = find_ptr(ptr);
  if (tmp != NULL)
    {
      tmp->used = 0;
      if (!tmp->next->root && !tmp->next->used)
	tmp = my_fusion(tmp, tmp->next);
      if (!tmp->prev->root && !tmp->prev->used)
	tmp = my_fusion(tmp->prev, tmp);
      if (tmp->next->root)
	delete_last(tmp);
    }
}
