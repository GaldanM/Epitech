/*
** foncs_action_list.c for fonc in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Lists
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:34:41 2015 Fares Doghri
** Last update Sun Jul  5 23:34:53 2015 Fares Doghri
*/

#include "action.h"

t_action      		*init_actions()
{
  t_action	*root;

  root = malloc(sizeof(t_action));
  if (root != NULL)
    {
      root->root = 1;
      root->next = NULL;
    }
  return (root);
}

e_bool 			push_action(t_action **root, ptr_fct fct, double time, char **cmd)
{
  t_action		*tmp;
  t_action		*nouv;

  if (count_actions(root) >= 10)
    return (FALSE);
  if ((nouv = malloc(sizeof(t_action))) == NULL)
    return (FALSE);
  nouv->fct = fct;
  nouv->cmds = cmd;
  nouv->time = time * 1000000;
  gettimeofday(&nouv->start, NULL);
  tmp = *root;
  while (tmp && tmp->next)
    tmp = tmp->next;
  tmp->next = nouv;
  nouv->next = NULL;
  return (TRUE);
}

e_bool 				delete_action(t_action **root)
{
  t_action		*tmp;

  tmp = (*root)->next;
  if (!tmp)
    return (FALSE);
  (*root)->next = tmp->next;
  free (tmp);
  if ((*root)->next)
    gettimeofday(&((*root)->next->start), NULL);
  return (TRUE);
}

int 			count_actions(t_action **root)
{
  int 		nb;
  t_action	*tmp;

  nb = 0;
  tmp = (*root)->next;
  while (tmp)
    {
      ++nb;
      tmp = tmp->next;
    }
  return (nb);
}
