/*
** realloc.c for malloc in /home/moulin_c/rendu/PSU_2014_malloc
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Feb  4 15:17:06 2015 Galdan MOULINNEUF
** Last update Fri Feb 13 15:27:51 2015 Galdan MOULINNEUF
*/

#include	<string.h>
#include	"malloc.h"

extern t_mdata	*g_root;

t_mdata		*find_ptr(void *to_find)
{
  t_mdata	*tmp;
  t_mdata	*tmp2;

  tmp = g_root->next;
  tmp2 = g_root->prev;
  while (!tmp->root && !tmp2->root)
    {
      if (tmp->end_mdata == to_find)
	return (tmp);
      else if (tmp2->end_mdata == to_find)
	return (tmp2);
      if (!tmp->root)
	tmp = tmp->next;
      if (!tmp2->root)
	tmp2 = tmp2->prev;
    }
  return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
  t_mdata	*tmp;
  void		*new_point;

  if (!ptr)
    return (malloc(size));
  if (!size && ptr)
    {
      free(ptr);
      return (NULL);
    }
  if ((tmp = find_ptr(ptr)) == NULL)
    return (NULL);
  if (size <= tmp->size)
    return (tmp->end_mdata);
  free(ptr);
  new_point = malloc(size);
  memcpy(new_point, tmp->end_mdata, tmp->size);
  return (new_point);
}
