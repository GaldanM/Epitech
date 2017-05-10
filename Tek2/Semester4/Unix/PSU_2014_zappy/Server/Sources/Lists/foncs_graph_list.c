/*
** foncs_graph_list.c for fonc in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Lists
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:34:15 2015 Fares Doghri
** Last update Sun Jul  5 23:34:20 2015 Fares Doghri
*/

#include 			"graph.h"

t_graph      		*init_graph()
{
  t_graph	*root;

  root = malloc(sizeof(t_graph));
  if (root != NULL)
    {
      root->root = 1;
      root->next = NULL;
    }
  return (root);
}

e_bool 			push_graph(t_graph **root, int id)
{
  t_graph		*nouv;

  if ((nouv = malloc(sizeof(t_graph))) == NULL)
    return (FALSE);
  nouv->id = id;
  nouv->next = (*root)->next;
  (*root)->next = nouv;
  return (TRUE);
}

e_bool 				delete_graph(t_graph **root, int id)
{
  t_graph	*tmp;
  t_graph	*prev;

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
