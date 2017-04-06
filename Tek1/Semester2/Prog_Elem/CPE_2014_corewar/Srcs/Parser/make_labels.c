/*
** init_doublelist.c for doublelist in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/raytracer
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  8 12:52:57 2014 moulin_c
** Last update Fri Apr  4 19:53:05 2014 moulin_c
*/

#include "../Includes/mylist.h"

t_labels	*make_labels(void)
{
  t_labels	*new_list;

  new_list = malloc(sizeof(t_labels));
  if (new_list != NULL)
    {
      new_list->prev = NULL;
      new_list->next = NULL;
    }
  else
    {
      write(2, "MALLOC FAILED\n", 15);
      exit(1);
    }
  return (new_list);
}
