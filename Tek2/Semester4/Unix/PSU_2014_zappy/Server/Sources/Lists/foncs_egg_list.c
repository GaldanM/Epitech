/*
** foncs_egg_list.c for  in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Lists
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:34:58 2015 Fares Doghri
** Last update Sun Jul  5 23:35:02 2015 Fares Doghri
*/

#include 		"egg.h"

t_egg      		*init_eggs()
{
  t_egg	*root;

  root = malloc(sizeof(t_egg));
  if (root != NULL)
    {
      root->root = 1;
      root->next = NULL;
    }
  return (root);
}

e_bool 			push_egg(t_egg **root, t_egg *src)
{
  t_egg		*nouv;
  static int 	id = 0;

  if ((nouv = malloc(sizeof(t_egg))) == NULL)
    return (FALSE);
  nouv->y = src->y;
  nouv->x = src->x;
  nouv->team = src->team;
  nouv->hatched = FALSE;
  nouv->id_player = src->id_player;
  nouv->id = id++;
  nouv->time = src->time;
  gettimeofday(&nouv->start, NULL);
  nouv->next = (*root)->next;
  (*root)->next = nouv;
  return (TRUE);
}

e_bool 				delete_egg(t_egg **root, int id)
{
  t_egg	*tmp;
  t_egg	*prev;

  prev = *root;
  tmp = (*root)->next;
  while (tmp != NULL && tmp->id != id)
    {
      prev = tmp;
      tmp = tmp->next;
    }
  if (!tmp)
    return (FALSE);
  prev->next = tmp->next;
  free(tmp);
  return (TRUE);
}
