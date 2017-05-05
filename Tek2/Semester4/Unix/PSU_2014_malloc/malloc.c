/*
** malloc.c for malloc in /home/moulin_c/rendu/PSU_2014_malloc
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Feb  3 21:12:40 2015 Galdan MOULINNEUF
** Last update Fri Feb 13 15:27:00 2015 Galdan MOULINNEUF
*/

#include	<unistd.h>
#include	"malloc.h"

t_mdata		*g_root = NULL;

static void	*new_field(size_t size)
{
  t_mdata	*new_elem;

  new_elem = sbrk(0);
  sbrk(sizeof(t_mdata) + size);
  new_elem->end = sbrk(0);
  new_elem->size = size;
  new_elem->root = 0;
  new_elem->used = 1;
  new_elem->prev = g_root->prev;
  new_elem->next = g_root;
  g_root->prev->next = new_elem;
  g_root->prev = new_elem;
  return (new_elem->end_mdata);
}

static int	init_list()
{
  if (g_root == NULL)
    {
      if ((g_root = sbrk(sizeof(t_mdata))) == (void *) -1)
	return (-1);
      g_root->prev = g_root;
      g_root->next = g_root;
      g_root->end = NULL;
      g_root->root = 1;
    }
  return (0);
}

void		*malloc(size_t size)
{
  t_mdata	*tmp;

  if (init_list() == -1)
    return (NULL);
  size = (((((size) - 1) >> 3) << 3) + 8);
  tmp = g_root->next;
  while (!tmp->root)
    {
      if (tmp->size >= size && !tmp->used)
  	{
  	  tmp->used = 1;
  	  return (tmp->end_mdata);
  	}
      tmp = tmp->next;
    }
  return (new_field(size));
}
