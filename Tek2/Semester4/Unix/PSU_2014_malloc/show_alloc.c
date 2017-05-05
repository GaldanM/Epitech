/*
** show_alloc.c for malloc in /home/moulin_c/rendu/PSU_2014_malloc
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Feb  3 21:14:34 2015 Galdan MOULINNEUF
** Last update Fri Feb 13 15:27:22 2015 Galdan MOULINNEUF
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"malloc.h"

extern t_mdata	*g_root;

void		show_alloc_mem()
{
  t_mdata	*tmp;

  if (g_root != NULL)
    {
      tmp = g_root->next;
      printf("break : %p\n", sbrk(0));
      while (!tmp->root)
	{
	  if (tmp->used)
	    printf("%p - %p : %zu octets\n", tmp->end_mdata, tmp->end, tmp->size);
	  tmp = tmp->next;
	}
    }
}
